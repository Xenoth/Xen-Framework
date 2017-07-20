//
// Created by Xenoth on 19/07/2017.
//

#ifndef XENFRAMEWORK_SKVMANAGER_H
#define XENFRAMEWORK_SKVMANAGER_H

#include <iostream>
#include <string>
#include <iosfwd>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>

class SKVManager
{
    public:

        static SKVManager& getInstance();

        SKVManager(SKVManager const&)       = delete;
        void operator=(SKVManager const&)   = delete;

        void createSKVFile(std::string pathfile);

        bool keyFound(std::string pathfile, std::string key);

        std::vector<std::string> valueFound(std::string pathfile, std::string value);

        std::string getValue(std::string pathfile, std::string key);

        std::map<std::string, std::string> getAllKeysValues(std::string pathfile);

        bool insertKeyValue(std::string pathfile, std::string key, std::string value);

        bool setValue(std::string pathfile, std::string key, std::string value);

    private:

        SKVManager(){};

        std::ifstream*                          openSKVFile(std::string pathfile);
        void                                    closeSKVFile(std::ifstream *file);

        std::vector<std::string>                getLines(std::ifstream *file);
        std::pair<std::string, std::string>     readLine(std::string line);




};


#endif //XENFRAMEWORK_SKVMANAGER_H
