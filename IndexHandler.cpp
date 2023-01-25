//
// Created by ryans on 11/30/2022.
//

#include "IndexHandler.h"
//constructor
IndexHandler::IndexHandler() {
parser = DocumentParser();
}
//parseDirectory method calls document parsers parseDirectory method
void IndexHandler::parseDirectory(std::string fileName){
    directory = fileName;
    DocumentParser::parseDirectory(fileName);
}
//fileWords method calls document parsers fileWords method
void IndexHandler::fileWords(std::ofstream &out) {
    out << directory << std::endl;
    //calls tree method to output words
    words.levelOrderFileOutput(out);
}
//filePersons
void IndexHandler::filePersons(std::ofstream &out) {
    out << directory << std::endl;
    //calls tree method to output persons
    persons.levelOrderFileOutput(out);
}
//fileOrganizations
void IndexHandler::fileOrganizations(std::ofstream &out) {
    out << directory << std::endl;
    //calls tree method to output organizations
    organizations.levelOrderFileOutput(out);
}



IndexHandler &IndexHandler::getInstance() {
    static IndexHandler instance;
    return instance;
}

void IndexHandler::addPerson(Word& word) {
    persons.insert(word);

}

void IndexHandler::addOrganization(Word& word) {
    organizations.insert(word);
}

void IndexHandler::addWord(Word& word) {
    words.insert(word);
}

void IndexHandler::printWords() {
    words.print();
}

void IndexHandler::printOrganizations() {
    organizations.print();

}

void IndexHandler::printPersons() {
    persons.print();

}

void IndexHandler::loadFromFiles(std::string wordsFile, std::string personsFile, std::string organizationsFile) {
    loadWords(wordsFile);
    loadPersons(personsFile);
    loadOrganizations(organizationsFile);
}

void IndexHandler::loadWords(std::string &fileName) {
    std::ifstream in(fileName);
    if(!in.is_open()){
        std::cout << "Error opening file" << std::endl;
        return;
    }
    std::string line;
    //get first line of document for directory
    std::getline(in, line);
    directory = line;
    while (std::getline(in, line)) {
        //getline for word and number of lines to read for documents
        //word is line split by :
        std::string word = line.substr(0, line.find('~'));
        //create word object with word
        Word w(word);
        //erase : at front of string
        line.erase(0, word.size() + 1);
        //number of documents is remaining text in line
        int numDocs = std::stoi(line);
        //for loop to read number of lines that are documents
        for (int i = 0; i < numDocs; i++) {
            //get line
            std::getline(in, line);
            //create documentID object with line
            documentID doc(line);
            //add documentID to word
            w.addDocID(doc);
        }
        //push word to words tree
        words.insert(w);
        //read extra blank line
        std::getline(in, line);
    }
}

void IndexHandler::loadPersons(std::string &fileName) {
    std::ifstream in(fileName);
    if(!in.is_open()){
        std::cout << "Error opening file" << std::endl;
        return;
    }
    std::string line;
    //get first line of document for directory
    std::getline(in, line);
    directory = line;
    while (std::getline(in, line)) {
//        std::cout << line << std::endl;
        //getline for word and number of lines to read for documents
        //word is line split by :
        std::string word = line.substr(0, line.find('~'));
        //create word object with word
        Word w(word);
        //erase | at front of string
        line.erase(0, word.size() + 1);
        //number of documents is remaining text in line
//        std::cout << "calling stoi with: " << line << std::endl;
        int numDocs = std::stoi(line);
        //for loop to read number of lines that are documents
        for (int i = 0; i < numDocs; i++) {
            //get line
            std::getline(in, line);
            //create documentID object with line
            documentID doc(line);
            //add documentID to word
            w.addDocID(doc);
        }
        //push word to words tree
        persons.insert(w);
        //read extra blank line
        std::getline(in, line);
    }
}

void IndexHandler::loadOrganizations(std::string &fileName) {
    std::ifstream in(fileName);
    if(!in.is_open()){
        std::cout << "Error opening file" << std::endl;
        return;
    }
    std::string line;
    //get first line of document for directory
    std::getline(in, line);
    directory = line;
    while (std::getline(in, line)) {
        //getline for word and number of lines to read for documents
        //word is line split by |
        std::string word = line.substr(0, line.find('~'));
        //create word object with word
        Word w(word);
        //erase : at front of string
        line.erase(0, word.size() + 1);
        //number of documents is remaining text in line
        int numDocs = std::stoi(line);
        //for loop to read number of lines that are documents
        for (int i = 0; i < numDocs; i++) {
            //get line
            std::getline(in, line);
            //create documentID object with line
            documentID doc(line);
            //add documentID to word
            w.addDocID(doc);
        }
        //push word to words tree
        organizations.insert(w);
        //read extra blank line
        std::getline(in, line);
    }
}

bool IndexHandler::findWord(const char *string) {
    return words.contains(string);
}
//findword using std::string
bool IndexHandler::findWord(std::string &string) {
    return words.contains(string);
}

void IndexHandler::clearWords() {
    words.makeEmpty();
}

void IndexHandler::clearPersons() {
    persons.makeEmpty();

}

void IndexHandler::clearOrganizations() {
    organizations.makeEmpty();

}

int IndexHandler::getNumWords() {
    return words.getNumNodes();
}

//getWord
Word IndexHandler::getWord(Word &word) {
    return words.getWord(word);
}
//getWord with string
Word IndexHandler::getWord(std::string &word) {
    return words.getWord(word);
}

Word IndexHandler::getWord(const char *word) {
    return words.getWord(word);
}

Word IndexHandler::getPerson(Word word) {
    return persons.getWord(word);
}

//getPerson with string
Word IndexHandler::getPerson(std::string word) {
    return persons.getWord(word);
}
//getOrganization
Word IndexHandler::getOrganization(Word word) {
    return organizations.getWord(word);
}
//getOrganization with string
Word IndexHandler::getOrganization(std::string word) {
    return organizations.getWord(word);
}

int IndexHandler::getNumPersons() {
    return persons.getNumNodes();
}

int IndexHandler::getNumOrganizations() {
    return organizations.getNumNodes();
}

std::string IndexHandler::getDirectory() {
    return directory;
}

