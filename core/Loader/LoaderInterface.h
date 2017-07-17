//
// Created by Xenoth on 17/07/2017.
//

#ifndef XENFRAMEWORK_LOADERINTERFACE_H
#define XENFRAMEWORK_LOADERINTERFACE_H

#include <string>
#include <map>

class HandlerInterface
{
    public:

        /** You should use this method to check that the filename is valid (extensions)
         *
         * @param resource
         * @return bool
         */
        virtual bool isValidFilename(std::string filename) = 0;

        /** Specify here which resource are valid
         *
         * @param resource
         * @return bool
         */
        virtual bool isValidResource(void* resource) = 0;

        /** Used to load the whole resources into the lod file
         * You should check for each key if the given filename is valid using HandlerInterface::isValidFilename()
         * Then you can check if the resource is valid with HandlerInterface::isValidResource()
         *
         * @param pathToLodFile
         * @return
         */
        virtual std::map<std::string, void*> loadResources(std::string pathToLodFile) = 0;
};

#endif //XENFRAMEWORK_LOADERINTERFACE_H
