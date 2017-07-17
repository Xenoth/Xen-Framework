//
// Created by Xenoth on 16/07/2017.
//

#ifndef XENFRAMEWORK_ABSTRACTHANDLER_H
#define XENFRAMEWORK_ABSTRACTHANDLER_H

#include "../Loader/AbstractLoader.h"

template <typename T>
class AbstractHandler
{
    public:
        inline AbstractHandler(AbstractLoader &loader) { this->resources = loader.loadResources(); };

        ~AbstractHandler()
        {
            for( const auto& sm_pair : resources )
                delete(sm_pair.second);
        };

        inline T* getResource(std::string key) { return resources.find(key)->second; };

    protected:
        std::map<std::string, T*> resources;

};


#endif //XENFRAMEWORK_ABSTRACTHANDLER_H
