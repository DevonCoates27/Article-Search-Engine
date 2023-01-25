//
// Created by ryans on 11/30/2022.
//

#ifndef FINALPROJEXAMPLES_INDEXHANDLER_H
#define FINALPROJEXAMPLES_INDEXHANDLER_H

#include <string>
#include "Word.h"
#include "DocumentParser.h"

class IndexHandler {
private:
    //3 avl maps
    AVLMap words;
    AVLMap organizations;
    AVLMap persons;
    DocumentParser parser;
    IndexHandler();
    std::string directory;
    void loadWords(std::string &fileName);
    void loadPersons(std::string &fileName);
    void loadOrganizations(std::string &fileName);

public:
    //getInstance
    static IndexHandler& getInstance();
    //parseDirectory
    void parseDirectory(string fileName);
    //addPerson
    void addPerson(Word& word);
    //addOrganization
    void addOrganization(Word& word);
    //addWord
    void addWord(Word& word);
    //printWords
    void printWords();
    //printOrganizations
    void printOrganizations();
    //printPersons
    void printPersons();

    void loadFromFiles(std::string wordsFile, std::string personsFile, std::string organizationsFile);


    void fileWords(ofstream &out);

    void filePersons(ofstream &out);

    void fileOrganizations(ofstream &out);

    bool findWord(const char *string);

    void clearWords();

    void clearPersons();

    void clearOrganizations();

    int getNumWords();

    Word getWord(Word &word);

    Word getPerson(Word word);

    Word getWord(string &word);

    Word getWord(const char *word);

    Word getPerson(string word);

    Word getOrganization(Word word);

    Word getOrganization(string word);

    int getNumPersons();

    int getNumOrganizations();

    bool findWord(string &string);

    std::string getDirectory();
};


#endif //FINALPROJEXAMPLES_INDEXHANDLER_H
