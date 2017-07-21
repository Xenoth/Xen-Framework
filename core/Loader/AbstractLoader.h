//
// Created by Xenoth on 20/07/2017.
//

#ifndef XENFRAMEWORK_ABSTRACTLOADER_H
#define XENFRAMEWORK_ABSTRACTLOADER_H


#include "../Tools/SKV/SKVManager.h"

class AbstractLoader {

    public:

        inline AbstractLoader() {};
        virtual ~AbstractLoader() = 0;

    protected:
        SKVManager &skvManager = SKVManager::getInstance();
};

inline AbstractLoader::~AbstractLoader() { };

#endif //XENFRAMEWORK_ABSTRACTLOADER_H
