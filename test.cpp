#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"


// add includes
#include "AVLMap.h"
#include "UserInterface.h"
#include "IndexHandler.h"


TEST_CASE("Check that Parsin File works", "[parseFile]")
{
//    UserInterface interface;
    IndexHandler::getInstance().parseDirectory("../sample_data/coll_2");
    REQUIRE(IndexHandler::getInstance().getNumWords() != 0);
    REQUIRE(IndexHandler::getInstance().getNumPersons() != 0);
    REQUIRE(IndexHandler::getInstance().getNumOrganizations() != 0);
}

TEST_CASE("Check that AVLTREE works", "[avlTree]")
{
    AVLMap map;
    Word word("test");
    Word word1("test1");
    Word word2("test2");
    Word word3("test3");
    Word word4("test4");
    map.insert(word);
    map.insert(word1);
    map.insert(word2);
    map.insert(word3);
    map.insert(word4);
    REQUIRE(map.contains("test"));
    REQUIRE(map.contains("test1"));
    REQUIRE(map.contains("test2"));
    REQUIRE(map.contains("test3"));
    REQUIRE(map.contains("test4"));
}

// you can run the test using Run CTest in the task bar or by running the tests executable.