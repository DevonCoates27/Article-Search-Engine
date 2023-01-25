//
// Created by ryans on 11/12/2022.
//

#ifndef FINALPROJEXAMPLES_AVLMAP_H
#define FINALPROJEXAMPLES_AVLMAP_H

#include "AVLTree.h"
#include <map>
#include "Word.h"

#endif //FINALPROJEXAMPLES_AVLMAP_H
class AVLMap {
private:
    AvlTree<Word> tree;
public:
    AVLMap();
    AVLMap(const AVLMap& other);
    AVLMap& operator=(const AVLMap& other);
    ~AVLMap();
    void makeEmpty();
    void add(string& word, documentID id);
    //find
    bool contains(string_view word) const;
    bool isEmpty();
    void printTree();
    //insert method
    void insert(Word& word);

    void print() const;

    Word & getWord(const Word &word) const;

    void levelOrderFileOutput(ostream &out) const;

    void levelOrderNonRecursive(ofstream &ofstream);
    //getNumNodes
    int getNumNodes() const;

    Word &getWord(const string &word) const;

    Word &getWord(const char *word) const;
};

