//
// Created by Xenoth on 19/07/2017.
//

#include "SKVManager.h"


SKVManager &SKVManager::getInstance()
{
    static SKVManager instance;
    return instance;
}

void SKVManager::createSKVFile(std::string pathfile)
{
    std::ofstream newFile(pathfile);

    if(!newFile.is_open())
        std::cerr << "unable to create new file \"" << pathfile << "\"" << std::endl;

    else
        newFile.close();
}

bool SKVManager::keyFound(std::string pathfile, std::string key)
{
    std::map<std::string, std::string> allKeysValues = getAllKeysValues(pathfile);
    std::map<std::string, std::string>::iterator it;

    return (allKeysValues.find(key) != allKeysValues.end());
}

std::vector<std::string> SKVManager::valueFound(std::string pathfile, std::string value)
{
    std::map<std::string, std::string> allKeysValues = getAllKeysValues(pathfile);

    std::vector<std::string> keys;
    for(auto& current: allKeysValues)
    {
        if(current.second == value)
            keys.push_back(current.first);
    }

    return keys;
}

std::string SKVManager::getValue(std::string pathfile, std::string key)
{
    std::map<std::string, std::string> allKeysValues = getAllKeysValues(pathfile);

    return allKeysValues.at(key);
}

std::map<std::string, std::string> SKVManager::getAllKeysValues(std::string pathfile)
{
    std::ifstream *file = openSKVFile(pathfile);
    std::vector<std::string> lines = getLines(file);
    std::map<std::string, std::string> allKeysValues;

    for(std::string line : lines)
    {
        allKeysValues.insert(readLine(line));
    }

    closeSKVFile(file);
    return allKeysValues;
}


bool SKVManager::insertKeyValue(std::string pathfile, std::string key, std::string value)
{
    if(keyFound(pathfile, key))
    {
        std::cerr << "Cannot duplicate key \"" << key << "\"" << std::endl;
        return false;
    }
    std::ofstream file(pathfile, std::ios::out | std::ios::app );
    file << key << ":" << value << std::endl;
    file.close();
}

bool SKVManager::setValue(std::string pathfile, std::string key, std::string value)
{
    if(!keyFound(pathfile, key))
        return false;

    std::string strReplace = key + ":" + getValue(pathfile, key);
    std::string strNew = key + ":" + value;
    std::ifstream filein(pathfile); //File to read from
    std::ofstream fileout("tmp.txt"); //Temporary file
    if(!filein || !fileout)
    {
        std::cerr << "Error opening files!" << std::endl;
        return false;
    }

    std::string strTemp;
    //bool found = false;
    while(filein >> strTemp)
    {
        if(strTemp == strReplace){
            strTemp = strNew;
        }
        strTemp += "\n";
        fileout << strTemp;
    }

    filein.close();
    fileout.close();

    filein.open("tmp.txt"); //File to read from
    fileout.open(pathfile); //Temporary file
    while(filein >> strTemp)
    {
        strTemp += "\n";
        fileout << strTemp;
    }

    filein.close();
    fileout.close();

    if( remove( "tmp.txt" ) != 0 )
        perror( "Error deleting \"tmp.txt\"" );

    return true;
}

std::ifstream* SKVManager::openSKVFile(std::string pathfile)
{
    std::ifstream *file = new std::ifstream(pathfile);

    if(!file->is_open())
    {
        std::cerr << "file invalid" << std::endl;
        exit(EXIT_FAILURE);
    }
    return file;
}

std::vector<std::string> SKVManager::getLines(std::ifstream *file)
{
    std::vector<std::string> lines;

    for( std::string line; getline( *file, line); )
    {
        lines.push_back(line);
    }
    return lines;
}

std::pair<std::string, std::string> SKVManager::readLine(std::string line)
{
    std::string key = line.substr(0, line.find(":"));
    std::string value = line.substr(line.find_first_of(":") + 1);
    return std::pair<std::string, std::string>(key, value);
}

void SKVManager::closeSKVFile(std::ifstream *file)
{
    if(file->is_open())
        file->close();

    delete(file);
}
