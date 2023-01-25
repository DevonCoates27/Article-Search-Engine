//
// Created by Devon Coates on 11/13/22.
//

#ifndef FINALPROJEXAMPLES_DOCUMENTID_H
#define FINALPROJEXAMPLES_DOCUMENTID_H
#include <string>


class documentID {
private:
    std::string ID;
    int relevancy;

public:
    //default constructor
    documentID() = default;
    //constructor to create from string
    explicit documentID(std::string &ID);
    //constructor
    documentID(std::string_view ID, int relevancy);
    //getters
    [[nodiscard]] std::string getID() const;
    int getRelevancy() const;
    //setters
    void setID(std::string ID);
    void setRelevancy(int relevancy);
    //print
    void print();

    bool operator==(const documentID &rhs) const;
    bool operator<(const documentID &rhs) const;
    //output stream operator overload
    friend std::ostream& operator<<(std::ostream& os, const documentID& docID);

    void increaseRelevancy();
};

#endif //FINALPROJEXAMPLES_DOCUMENTID_H
