//
// Created by Xenoth on 20/07/2017.
//

#include <iostream>
#include <cstdlib>
#include "SKVManager.h"

#define TEST_FILE "../test.txt"

void testAllKeysValues(SKVManager &skvManager);
void testKeyFound(SKVManager &skvManager);
void testValueFound(SKVManager &skvManager);
void testGetValue(SKVManager &skvManager);

int main(int argc, char** argv)
{
    SKVManager &skvManager = SKVManager::getInstance();

    testAllKeysValues(skvManager);
    testKeyFound(skvManager);
    testValueFound(skvManager);
    testGetValue(skvManager);



    return EXIT_SUCCESS;
}

void testAllKeysValues(SKVManager &skvManager)
{
    std::map<std::string, std::string> allKeysValues = skvManager.getAllKeysValues(TEST_FILE);

    std::cout << std::endl << "SKVManager::getAllKeysValues()" << std::endl;

    for(auto& current : allKeysValues)
    {
        std::cout <<  current.first << " : " << current.second << std::endl;
    }
}

void testKeyFound(SKVManager &skvManager)
{
    std::cout << std::endl << "SKVManager::keyFound()" << std::endl;
    std::cout << "\"foo\" key found ? " << skvManager.keyFound(TEST_FILE, "foo") << std::endl;
    std::cout << "\"missing\" key found ? " << skvManager.keyFound(TEST_FILE, "missing") << std::endl;
}

void testValueFound(SKVManager &skvManager)
{
    std::cout << std::endl << "SKVManager::ValueFound()" << std::endl;
    std::cout << "\"foo\" value found ? " << skvManager.valueFound(TEST_FILE, "foo").size() << std::endl;
    std::cout << "\"world\" value found ? " << skvManager.valueFound(TEST_FILE, "world").size() << std::endl;
    std::cout << "\"hello\" value found ? " << skvManager.valueFound(TEST_FILE, "hello").size() << std::endl;
}

void testGetValue(SKVManager &skvManager)
{
    std::cout << std::endl << "SKVManager::GetValue()" << std::endl;
    std::cout << "\"hello\" value : " << skvManager.getValue(TEST_FILE, "hello") << std::endl;
    std::cout << "\"foo\" value : " << skvManager.getValue(TEST_FILE, "foo") << std::endl;
}