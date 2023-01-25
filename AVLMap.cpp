//
// Created by Devon Coates on 11/13/22.
//

#include "AVLMap.h"

AVLMap::AVLMap()= default;
//destructor
AVLMap::~AVLMap() {
    tree.makeEmpty();
}

AVLMap &AVLMap::operator=(const AVLMap &other) {
    tree = other.tree;
    return *this;
}

AVLMap::AVLMap(const AVLMap &other) {
    tree = other.tree;
}


void AVLMap::add(string& input, const documentID id) {
    Word word(input);
    word.addDocID(id);
    tree.insert(word);
}

bool AVLMap::contains(const string_view input) const {
    Word word(input);
    return tree.contains(word);
}

void AVLMap::makeEmpty(){
    tree.makeEmpty();
}

bool AVLMap::isEmpty() {
    return tree.isEmpty();
}

//getword returns a reference to word in tree
Word& AVLMap::getWord(const Word& word) const{
    //use get command to return word reference
    return *tree.get(word, tree.getRoot());
}
//getword with string
Word& AVLMap::getWord(const string& word) const{
    Word temp(word);
    //use get command to return word reference
    return *tree.get(temp, tree.getRoot());
}

Word& AVLMap::getWord(const char *word) const{
    Word temp(word);
    //use get command to return word reference
    return *tree.get(temp, tree.getRoot());
}


//print tree
void AVLMap::print() const {
    tree.prettyPrintTree();
}

//level order file output as level order traversal
void AVLMap::levelOrderFileOutput(ostream &out) const {
    tree.levelOrder(out);
}

void AVLMap::printTree() {
    tree.prettyPrintTree();
}

void AVLMap::insert(Word& word) {
    //if tree already contains word add document
    if(contains(word.getWord())){
        Word& temp = getWord(word);
        for(const auto& docID : word.getDocIDS()){
            temp.addDocID(docID);
        }
    }else{
        tree.insert(word);
    }
}

void AVLMap::levelOrderNonRecursive(ofstream &ofstream) {
    cout << "height: " << tree.getHeight() << endl;
    tree.levelOrderRecursive(ofstream);
}

int AVLMap::getNumNodes() const {
    return tree.getNumNodes();
}


