//
// Created by Xenoth on 17/07/2017.
//

#ifndef XENFRAMEWORK_HANDLERINTERFACE_H
#define XENFRAMEWORK_HANDLERINTERFACE_H

#include <string>

class HandlerInterface
{
    public:

        /** This method will return a resource pointed for the given key (key given into the lod file)
         *
         * @param key
         * @return void* ptr of a resource
         */
        virtual void* getResource(std::string key) = 0;
};

#endif //XENFRAMEWORK_HANDLERINTERFACE_H
