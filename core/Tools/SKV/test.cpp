//
// Created by Xenoth on 20/07/2017.
//

#include <iostream>
#include <cstdlib>
#include "SKVManager.h"

#define TEST_FILE "../test.txt"
#define NEW_SKV_FILE "../created_skv_file.txt"

void testAllKeysValues(SKVManager &skvManager);
void testKeyFound(SKVManager &skvManager);
void testValueFound(SKVManager &skvManager);
void testGetValue(SKVManager &skvManager);

void testCreatingAndInserting(SKVManager &skvManager);
void testSetValue(SKVManager &skvManager);

int main(int argc, char** argv)
{
    SKVManager &skvManager = SKVManager::getInstance();

    testAllKeysValues(skvManager);
    testKeyFound(skvManager);
    testValueFound(skvManager);
    testGetValue(skvManager);

    testCreatingAndInserting(skvManager);
    testSetValue(skvManager);

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

void testCreatingAndInserting(SKVManager & skvManager)
{
    std::cout << std::endl << "SKVManager::createSKVFile()" << std::endl;
    skvManager.createSKVFile(NEW_SKV_FILE);
    std::cout << std::endl << "SKVManager::insertKeyValue()" << std::endl;
    std::cout << "Inserting key \"1\" value \"hello\"" << std::endl;
    skvManager.insertKeyValue(NEW_SKV_FILE, "1", "hello");
    std::cout << "Inserting key \"2\" value \"world!\"" << std::endl;
    skvManager.insertKeyValue(NEW_SKV_FILE, "2", "world!");
    std::cout << std::endl << "SKVManager::getAllKeysValues()" << std::endl;
    std::map<std::string, std::string> allKeysValues = skvManager.getAllKeysValues(NEW_SKV_FILE);
    for(auto& current : allKeysValues)
    {
        std::cout <<  current.first << " : " << current.second << std::endl;
    }
}

void testSetValue(SKVManager &skvManager)
{
    std::cout << std::endl << "SKVManager::setValue()" << std::endl;
    std::cout << "\"foo\" value : " << skvManager.getValue(TEST_FILE, "foo") << std::endl;
    skvManager.setValue(TEST_FILE, "foo", "windows");
    std::cout << "\"foo\" value : " << skvManager.getValue(TEST_FILE, "foo") << std::endl;
    skvManager.setValue(TEST_FILE, "foo", "linux");
    std::cout << "\"foo\" value : " << skvManager.getValue(TEST_FILE, "foo") << std::endl;

}