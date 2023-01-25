/**
 * Example code related to final project
 */
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <iomanip>

// RapidJSON headers we need for our parsing.
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/document.h"
#include "DocumentParser.h"

//index handler
#include "IndexHandler.h"
#include "UserInterface.h"

using namespace rapidjson;
using namespace std;
namespace fs = std::filesystem;

// Function Prototypes
void testReadJsonFile(const string &fileName);
void testFileSystem(const string &path);

int main()
{
    //user interface object
    UserInterface ui;
    ui.introduction();


//    //output stream
//    ofstream out("../output/outputWords.txt");
//    //path to the directory
//    string path = "../sample_data/coll_3";
//    IndexHandler::getInstance().parseDirectory(path);
//    std::cout << "here!" << std::endl;
//    cout << "Numwords: " << IndexHandler::getInstance().getNumWords() << endl;
//    IndexHandler::getInstance().fileWords(out);
//    ofstream out2("../output/outputPersons.txt");
//    IndexHandler::getInstance().filePersons(out2);
//    ofstream out3("../output/outputOrgs.txt");
//    IndexHandler::getInstance().fileOrganizations(out3);
//    IndexHandler::getInstance().clearWords();
//    IndexHandler::getInstance().clearPersons();
//    IndexHandler::getInstance().clearOrganizations();
//    out.close();
//    out2.close();
//    out3.close();
//    IndexHandler::getInstance().loadFromFiles("../output/outputWords.txt", "../output/outputPersons.txt", "../output/outputOrgs.txt");
//    cout << "Numwords: " << IndexHandler::getInstance().getNumWords() << endl;
//    ofstream out4("../output/outputWords2.txt");
//    IndexHandler::getInstance().fileWords(out4);
    return 0;
}

/**
 * example code that reads and parses a json file and extracts the title and person
 * entities.
 * @param fileName filename with relative or absolute path included.
 */
void testReadJsonFile(const string &fileName)
{

    // open an ifstream on the file of interest and check that it could be opened.
    ifstream input(fileName);
    if (!input.is_open())
    {
        cerr << "cannot open file: " << fileName << endl;
        return;
    }

    // Create a RapidJSON IStreamWrapper using the file input stream above.
    IStreamWrapper isw(input);

    // Create a RapidJSON Document object and use it to parse the IStreamWrapper object above.
    Document d;
    d.ParseStream(isw);

    // Now that the document is parsed, we can access different elements the JSON using
    // familiar subscript notation.

    // This accesses the -title- element in the JSON. Since the value
    //  associated with title is a string (rather than
    //  an array or something else), we call the GetString()
    //  function to return the actual title of the article
    //  as a c-string.
    auto val = d["title"].GetString();
    cout << "Title: " << val << "\n";

    // The Persons entity for which you're building a specific
    //  inverted index is contained in top level -entities- element.
    //  So that's why we subscript with ["entities"]["persons"].
    //  The value associated with entities>persons is an array.
    //  So we call GetArray() to get an iterable collection of elements
    auto persons = d["entities"]["persons"].GetArray();

    // We iterate over the Array returned from the line above.
    //  Each element kind of operates like a little JSON document
    //  object in that you can use the same subscript notation
    //  to access particular values.
    cout << "  Person Entities + sentiment:"
         << "\n";
    for (auto &p : persons)
    {
        cout << "    > " << setw(30) << left << p["name"].GetString()
             << setw(10) << left << p["sentiment"].GetString() << "\n";
    }

    cout << endl;

    input.close();
}

/**
 * example code for how to traverse the filesystem using std::filesystem
 * which is new for C++17.
 *
 * @param path an absolute or relative path to a folder containing files
 * you want to parse.
 */
void testFileSystem(const string &path)
{

    // recursive_director_iterator used to "access" folder at parameter -path-
    // we are using the recursive iterator so it will go into subfolders.
    // see: https://en.cppreference.com/w/cpp/filesystem/recursive_directory_iterator
    auto it = filesystem::recursive_directory_iterator(path);

    // loop over all the entries.
    for (const auto &entry : it)
    {

        cout << "--- " << setw(60) << left << entry.path().c_str() << " ---" << endl;

        // We only want to attempt to parse files that end with .json...
        if (entry.is_regular_file() && entry.path().extension().string() == ".json")
        {
            testReadJsonFile(entry.path().string());
        }
    }
}
