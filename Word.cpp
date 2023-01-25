//
// Created by ryans on 11/12/2022.
//

#include <iostream>
#include <algorithm>
#include "Word.h"

Word::Word(std::string_view word) : word(word){

}

void Word::addDocID(const documentID &docID) {
    //check if docID is already in the set
    if(contains(docID)){
        //if it is increase relevancy of docID
        increaseRelevancy(docID);
    }else{
        //if not add it to the set
        docIDS.insert(docID);
    }
}

void Word::removeDocID(const documentID &docID) {
    this->docIDS.erase(docID);
}

void Word::print() const{
    std::cout << word << ": ";
    for(auto docID : docIDS){
        docID.print();
    }
    std::cout << std::endl;
}

std::string Word::getWord() const{
    return word;
}

std::unordered_set<documentID, Word::Hash> Word::getDocIDS() const{
    return docIDS;
}

bool Word::operator==(const Word &rhs) const {
    return word == rhs.getWord();
}

bool Word::operator!=(const Word &rhs) const {
    return !(rhs == *this);
}

bool Word::operator<(const Word &rhs) const{
    int x = word.compare(rhs.getWord());
    if(x < 0)
        return true;
    else
        return false;
}

//bool Word::operator>(const Word &rhs) const{
//    return !(rhs < *this);
//}


//output stream overload that prints word
std::ostream &operator<<(std::ostream &os, const Word &word) {
    os << word.getWord()<<"~" << word.getDocIDS().size()<<"\n";
    for(auto docID : word.getDocIDS()){
        os << '\t' << docID;
        os << "\n";
    }
    return os;
}

bool Word::contains(const documentID &docID) const {
    return docIDS.find(docID) != docIDS.end();
}
//function that returns docID that matches DocID passed in
///this function should NEVER be called without first calling contains
documentID Word::getDocID(const documentID &docID) const {
    for(auto doc : docIDS){
        if(doc == docID)
            return doc;
    }
    return documentID("ERROR", 0);
}

void Word::addDocIDS(const std::unordered_set<documentID, Word::Hash> &docIDS) {
    for(auto docID : docIDS){
        this->docIDS.insert(docID);
    }
}

void Word::increaseRelevancy(const documentID &docID) {
    if(contains(docID)){
        documentID temp = getDocID(docID);
        temp.increaseRelevancy();
        removeDocID(docID);
        addDocID(temp);
    }
}

Word::Word(char *word) : word(word){

}
