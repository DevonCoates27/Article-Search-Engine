//
// Created by Devon Coates on 11/13/22.
//

#include <cstring>
#include <iostream>
#include "documentID.h"

documentID::documentID(std::string_view ID, int relevancy) {
    this->ID = ID;
    this->relevancy = relevancy;
}

std::string documentID::getID() const{
    return ID;
}

int documentID::getRelevancy() const{
    return relevancy;
}

void documentID::setID(std::string ID) {
    this->ID = ID;

}

void documentID::setRelevancy(int relevancy) {
    this->relevancy = relevancy;

}

void documentID::print() {
    std::cout << "ID: " << ID << " Relevancy: " << relevancy;
}

bool documentID::operator==(const documentID &rhs) const {
    return ID == rhs.ID;
}
//compare operator overload
bool documentID::operator<(const documentID &rhs) const {
    return ID.compare(rhs.getID()) < 0;
}
//struct for std::sort by relevancy
struct docGreaterRel
{
    bool operator()(const documentID& lx, const documentID& rx ) const {
        return lx.getRelevancy() < rx.getRelevancy();
    }
};

//output stream overload docID
std::ostream& operator<<(std::ostream& os, const documentID& docID){
    os << docID.getID() << "|" << docID.getRelevancy();
    return os;
}

void documentID::increaseRelevancy() {
    relevancy++;
}

documentID::documentID(std::string& ID) {
    //fields are separated by |
    //ID|relevancy|title|datePublished|author|publisher
    //parse string by | and set relevant fields
    //remove "\t" from string
    ID.erase(0, 1);
    std::string delimiter = "|";
    size_t pos = 0;
    std::string token;
    int i = 0;
    while ((pos = ID.find(delimiter)) != std::string::npos) {
        token = ID.substr(0, pos);
        if(i == 0){
            this->ID = token;
        }else if(i == 1){
            this->relevancy = std::stoi(token);
        }
        ID.erase(0, pos + delimiter.length());
        i++;
    }


}