//
// Created by ryans on 11/12/2022.
//

#ifndef FINALPROJEXAMPLES_WORD_H
#define FINALPROJEXAMPLES_WORD_H

#include <string>
#include <vector>
#include <unordered_set>
#include "documentID.h"

//clas word with comparable interface and vector of docID's
class Word {
private:
    //custom hash for documentID just uses the std::hash function for the string
    struct Hash {
        size_t operator()(const documentID &interval) const {
            return std::hash<std::string>()(interval.getID());
        }
    };
    std::string word;
    //unordered_set of strings
    std::unordered_set<documentID, Hash> docIDS;

public:
    //default constructor
    Word() = default;
    explicit Word(std::string_view word);
    explicit Word(char *word);
    void addDocID(const documentID &docID);
    void removeDocID(const documentID &docID);
    void print() const;
    [[nodiscard]] std::string getWord() const;
    [[nodiscard]] std::unordered_set<documentID, Hash> getDocIDS() const;
    //add docIDS
    void addDocIDS(const std::unordered_set<documentID, Hash> &docIDS);
    bool operator==(const Word &rhs) const;
    bool operator!=(const Word &rhs) const;
    bool operator<(const Word &rhs) const;
    //contains function to see if it contains the docID
    bool contains(const documentID &docID) const;
    //output stream operator overload
    friend std::ostream& operator<<(std::ostream& os, const Word& word);

    documentID getDocID(const documentID &docID) const;
    //increase relevancy of docID
    void increaseRelevancy(const documentID &docID);
};


#endif //FINALPROJEXAMPLES_WORD_H
