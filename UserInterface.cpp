//
// Created by Devon Coates on 12/3/22.
//

#include "UserInterface.h"
#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "IndexHandler.h"
#include "documentID.h"
#include "porter2_stemmer-master/porter2_stemmer.h"
#include "istreamwrapper.h"
#include "document.h"
#include <set>
#include <cstring>

UserInterface::UserInterface(){
    std::ifstream in("../stopwords.txt");
    std::string word;
    //insert each word into a map
    while (in >> word) {
        stopWords.insert(word);
    }
};

void UserInterface::introduction() {
    //Make variables
    int option;
    int temp = 0;

    //verify
    while(true) {
        option = showOptions();
        //check number
        if (option == 1) {
            createIndex();
            temp = 1;
        }
        else if (option == 2 && temp == 1)
            writeIndex();
        else if (option == 2 && temp == 0)
            std::cout << "Index nonexistent" << std::endl;
        else if(option == 3)
            readIndex();
        else if (option == 4)
            query();
        else if (option == 5)
            showStats();
        else if(option == 6)
            break;
        else {
            std::cout << "Option not available\nOption: ";
            std::cin >> option;
            std::cout << std::endl;
        }
    }

    //close program
    std::cout << "Thank you for visiting!" << std::endl;
}

void UserInterface::createIndex() {
    //start clock
    auto start = std::chrono::steady_clock::now();

    //make variables
    std::string path;

    //ask for filename
    std::cout << "Enter a pathname: ";
    std::cin >> path;
    std::cout << "\n" << std::endl;

    //create index
    IndexHandler::getInstance().parseDirectory(path);

    //end clock
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    createIndexTime = elapsed_seconds.count();
}

void UserInterface::writeIndex() {
    //start clock
    auto start = std::chrono::steady_clock::now();

    //write the index
    ofstream out1("../output/outputWords.txt");
    IndexHandler::getInstance().fileWords(out1);
    ofstream out2("../output/outputPersons.txt");
    IndexHandler::getInstance().filePersons(out2);
    ofstream out3("../output/outputOrgs.txt");
    IndexHandler::getInstance().fileOrganizations(out3);

    //end clock
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    writeIndexTime = elapsed_seconds.count();
    //close files
    out1.close();
    out2.close();
    out3.close();
}

void UserInterface::readIndex() {
    //start clock
    auto start = std::chrono::steady_clock::now();
    std::string path1;
    std::string path2;
    std::string path3;

    //ask for file
    std::cout << "Enter a words pathname: ";
    std::cin >> path1;
    std::cout << "\nEnter a persons pathname: ";
    std::cin >> path2;
    std::cout << "\nEnter an organizations pathname: ";
    std::cin >> path3;
    std::cout << "\n" << std::endl;

    //read the index
    IndexHandler::getInstance().loadFromFiles(path1, path2, path3);

    //end clock
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    readIndexTime = elapsed_seconds.count();
}

void UserInterface::query() {
    //start clock
    auto start = std::chrono::steady_clock::now();

    //create variables
    std::string query;
    std::vector<std::string> words;
    std::vector<std::vector<documentID>> allDocs;
    std::vector<documentID> docs;

    //ask query
    std::cout << "Enter a query: ";
    //use getline to get query from cin
    std::getline(std::cin >> std::ws, query);
    std::cout << std::endl;

    //save query into vector
    queries.push_back(query);

    //split query string by " " using std::string::find
    size_t pos = 0;
    std::string temp;
    while (pos != std::string::npos) {
        pos = query.find(' ');
        //if word is stop word do not add to vector
        temp = query.substr(0, pos);
        query.erase(0, pos + 1);
        //remove non ascii characters
        temp.erase(std::remove_if(temp.begin(), temp.end(), [](char c) { return !std::isalnum(c); }), temp.end());
        //tolower
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        //if word smaller than 3 characters do not add to vector
        if (temp.size() < 2) {
            //if word is not stop word add to vector
            continue;
        }
        else if (stopWords.find(temp) != stopWords.end()) {
            continue;
        }
        //if word is not stop word stem and add to tree
        else {
            Porter2Stemmer::trim(temp);
            Porter2Stemmer::stem(temp);
            words.push_back(temp);
        }
    }
    //cross-reference words
    for(auto & word : words){
        if(IndexHandler::getInstance().findWord(word)){
            for(const auto& elem: IndexHandler::getInstance().getWord(word).getDocIDS()){
                docs.push_back(elem);
            }
            allDocs.push_back(docs);
        }
    }
    //get intersection of sets in allDocs
    for(int i = 0; i < allDocs.size(); i++){
        if(i == 0){
            docs = allDocs[i];
        }
        else{
           //custom set intersection that adds relevency of matching docs and pushes to vector
              std::vector<documentID> temp;
              for(int j = 0; j < docs.size(); j++){
                    for(int k = 0; k < allDocs[i].size(); k++){
                        if(docs[j].getID() == allDocs[i][k].getID()){
                            documentID tempDoc(docs[j].getID(), docs[j].getRelevancy() + allDocs[i][k].getRelevancy());
                            temp.push_back(tempDoc);
                        }
                    }
              }
        }
    }
    //sort the vector by relevancy
    std::sort(docs.begin(), docs.end(), [](const documentID & a, const documentID & b){
        return a.getRelevancy() > b.getRelevancy();
    });
    //print first 15 documents
    for(int i = 0; i < 15; i++){
        if(docs.size() > i){
            std::cout << getDocInfo(docs[i].getID())<< " " <<  docs[i].getID() << std::endl;
        }
    }

    //end clock
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    double time = elapsed_seconds.count();
    //save query time
    queryTime.push_back(time);
}

void UserInterface::showStats() {
    //print stats
    if(createIndexTime != 0){
        std::cout << "Time to create index: " << createIndexTime << " seconds" << std::endl;
    }
    if(writeIndexTime != 0){
        std::cout << "Time to write index: " << writeIndexTime << " seconds" << std::endl;
    }
    if(readIndexTime != 0){
        std::cout << "Index reading time: " << readIndexTime << "s" << std::endl;
    }
    for(size_t i = 0; i < queries.size(); i++){
        std::cout << "Query: " << queries[i] << std::endl;
        std::cout << "\tQuery time: " << queryTime[i] << "s" << std::endl;
    }
    //print total number of files parsed
    std::cout << "Total number of files parsed: " << DocumentParser::getNumFiles() << std::endl;
    //print total number of words in index
    std::cout << "Total number of words in index: " << IndexHandler::getInstance().getNumWords() << std::endl;
}

int UserInterface::showOptions() {
    int option = 0;

    //Take option
    std::cout << "Welcome to RC Search!" << std::endl;
    std::cout << "    (1) Create index\n" <<
              "    (2) Write an index to a file\n" <<
              "    (3) Load an index from a file\n" <<
              "    (4) Enter a query\n" <<
              "    (5) Output stats\n" <<
              "    (6) Exit\n" << std::endl;
    std::cout << "Option: ";
    std::cin >> option;
    std:: cout << "\n" << std::endl;

    return option;
}
//function to get basic info about a document return type string
std::string UserInterface::getDocInfo(std::string docName) {
//use rapid json to get title
    std::string title;
    std::string date;
    std::string info;
    std::string path = IndexHandler::getInstance().getDirectory() + '/' + docName;
    std::ifstream f(path);
    //check if file is open
    if (!f.is_open()) {
        std::cerr << "cannot open file: " << docName << std::endl;
    }
    //parse the file
    rapidjson::IStreamWrapper isw(f);
    // Create a RapidJSON Document object and use it to parse the IStreamWrapper object above.
    rapidjson::Document d;
    d.ParseStream(isw);
    //parse title
    title = d["title"].GetString();
    //parse published
    date = d["published"].GetString();
    info = title + "\n\t" + date;
    return info;
}

UserInterface::~UserInterface() {

}
