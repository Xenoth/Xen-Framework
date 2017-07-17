//
// Created by Xenoth on 16/07/2017.
//

#ifndef XENFRAMEWORK_TEXTURESLOADER_H
#define XENFRAMEWORK_TEXTURESLOADER_H


#include <fstream>
#include <iostream>
#include "AbstractLoader.h"

template <typename T>
class TexturesLoader : public AbstractLoader<T>
{
    public:
        TexturesLoader<T>(std::string from_file) : AbstractLoader<T>(from_file) {};

        std::map<std::string, T*> loadResources()
        {
            std::map<std::string, T*> resources;

            std::ifstream input( this->from_file );
            if(!input.is_open())
                throw std::string(MISSING_RESOURCES_FILE);

            for( std::string line; getline( input, line ); )
            {
                T *tmp = new T;
                std::string key = line.substr(0, line.find(";"));
                line = line.substr(line.find_first_of(";") + 1);


                if(!tmp->loadFromFile(line)) {
                    std::cerr << "Was Unable to load the file " << key << " (" << line <<")" << std::endl;
                    continue;
                }
                resources.insert({key, tmp});
                std::cout << "File " << key << " (" << line <<") loaded" << std::endl;
            }
            return resources;
        }
};


#endif //XENFRAMEWORK_TEXTURESLOADER_H
