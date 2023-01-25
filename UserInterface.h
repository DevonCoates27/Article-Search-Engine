//
// Created by Devon Coates on 12/3/22.
//

#ifndef FINALPROJEXAMPLES_USERINTERFACE_H
#define FINALPROJEXAMPLES_USERINTERFACE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

class UserInterface {
private:
    //statistic variables
    double createIndexTime = 0;
    double writeIndexTime = 0;
    double readIndexTime = 0;
    std::vector<std::string> queries{};
    std::vector<double> queryTime{};
    std::set<std::string> stopWords;

public:
    UserInterface();

    virtual ~UserInterface();

    static int showOptions();
    void introduction();
    void createIndex();
    void writeIndex();
    void readIndex();
    void query();
    void showStats();

    std::string getDocInfo(std::string docName);
};


#endif //FINALPROJEXAMPLES_USERINTERFACE_H
