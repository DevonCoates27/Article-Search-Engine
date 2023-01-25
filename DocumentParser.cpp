//
// Created by ryans on 11/4/2022.
//
//iostream
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <filesystem>
#include <set>
#include "DocumentParser.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "documentID.h"
#include "porter2_stemmer-master/porter2_stemmer.h"
#include "IndexHandler.h"

namespace fs = std::filesystem;


//constructor
DocumentParser::DocumentParser() {
    //create a map of stopwords from stopwords.txt
    std::ifstream in("../stopwords.txt");
    std::string word;
    //insert each word into a map
    while (in >> word) {
        stopWords.insert(word);
    }
}
//destructor


void DocumentParser::parseDirectory(const std::string directoryName) {
    for (const auto &entry: fs::directory_iterator(directoryName)) {
        parseAll(entry.path().filename().string(), directoryName);
    }
}

void DocumentParser::parseAll(const std::string &filename, const std::string &path) {
    files++;
//    std::cout << "parsing all of " << filename << std::endl;
if(files % 1000 == 0){
    std::cout << "parsed " << files << " files" << std::endl;
}
    //open file
    std::ifstream f(path + "/" + filename);
    //check if file is open
    if (!f.is_open()) {
        std::cerr << "cannot open file: " << filename << std::endl;
    }
    //parse the file
    rapidjson::IStreamWrapper isw(f);
    // Create a RapidJSON Document object and use it to parse the IStreamWrapper object above.
    rapidjson::Document d;
    d.ParseStream(isw);
    std::string text = d["text"].GetString();
    //get the persons
    auto persons = d["entities"]["persons"].GetArray();
    //get the organizations
    auto organizations = d["entities"]["organizations"].GetArray();

    //for each person add person to person tree in index handler
    for (auto &p : persons) {
        //create a word object for each person and push to vector
        std::string person = p["name"].GetString();
        std::transform(person.begin(), person.end(), person.begin(), ::tolower);
        Word personObj(person);
        documentID docID(filename, 1);
        personObj.addDocID(docID);
        IndexHandler::getInstance().addPerson(personObj);
    }
    //for each organization add organization to organization tree in index handler
    for (auto &p : organizations) {
        //create a word object for each organization
        std::string organization = p["name"].GetString();
        std::transform(organization.begin(), organization.end(), organization.begin(), ::tolower);
        Word organizationObj(organization);
        documentID docID(filename, 1);
        organizationObj.addDocID(docID);
        IndexHandler::getInstance().addOrganization(organizationObj);
    }
    //for each word in the text add word to word tree in index handler
    //parse text by delimiter " " and add each word to the word tree
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    while ((pos = text.find(delimiter)) != std::string::npos) {
        token = text.substr(0, pos);
        //remove non ascii charact
        token.erase(std::remove_if(token.begin(), token.end(), [](char c) { return !std::isalnum(c); }), token.end());
        //remove new line char
        token.erase(std::remove(token.begin(), token.end(),
                                '\n'), token.end());
        //tolower
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        //if token less than 3 chars cont
        if (token.length() < 3) {
            text.erase(0, pos + delimiter.length());
            continue;
        }
        //check if token is in stopwords and cont
        if (DocumentParser::getInstance().stopWords.find(token) != DocumentParser::getInstance().stopWords.end()) {
            text.erase(0, pos + delimiter.length());
            continue;
        }
        //pass token through porter stemmer
        Porter2Stemmer::trim(token);
        Porter2Stemmer::stem(token);
        Word wordObj(token);
        documentID docID(filename, 1);
        wordObj.addDocID(docID);
        IndexHandler::getInstance().addWord(wordObj);
        text.erase(0, pos + delimiter.length());
    }
}

DocumentParser DocumentParser::getInstance() {
    static DocumentParser instance;
    return instance;
}

//getNumFiles
int DocumentParser::getNumFiles() {
    return files;
}


