//
// Created by ryans on 11/4/2022.
//

#ifndef FINALPROJEXAMPLES_DOCUMENTPARSER_H
#define FINALPROJEXAMPLES_DOCUMENTPARSER_H

#include "Word.h"
#include "documentID.h"
#include "AVLMap.h"

class IndexHandler;
class DocumentParser {
    //uses the rapidjson library to parse the json file
    //returns word objects each with the documentID and the word
public:
    DocumentParser();
    static int getNumFiles();

static void parseDirectory(std::string fileName);
private:
    inline static int files = 0;
    std::unordered_set<std::string> stopWords;

    static void parseAll(const std::string &filename, const std::string &path);

    static DocumentParser getInstance();
};


#endif //FINALPROJEXAMPLES_DOCUMENTPARSER_H
