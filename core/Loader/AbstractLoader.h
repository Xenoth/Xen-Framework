//
// Created by Xenoth on 16/07/2017.
//
#ifndef XENFRAMEWORK_ABSTRACTLOADER_H
#define XENFRAMEWORK_ABSTRACTLOADER_H

#include <string>
#include <map>

#define MISSING_RESOURCES_FILE "resources file not found"

template <typename T>
class AbstractLoader
{
    public:
        inline AbstractLoader<T>(std::string from_file) { this->from_file = from_file; };

        virtual std::map<std::string, T*> loadResources() = 0;

    protected:
        std::string from_file;
};


#endif //XENFRAMEWORK_ABSTRACTLOADER_H

