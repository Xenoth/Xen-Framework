//
// Created by Xenoth on 16/07/2017.
//

#ifndef XENFRAMEWORK_KERNEL_H
#define XENFRAMEWORK_KERNEL_H

#include "Loader/AssetsLoader.h"

class Kernel
{
    public :

        const std::string CONFIG_PATH= "../config/config.skv";

        inline Kernel() {};

        void initKernel();

        //AssetsHandler assetsHandler;

    private:
        void readConfigFile();
        void initHandlers();

        std::string textures_lod;
        std::string shaders_lod;
        std::string fonts_lod;
        std::string soundBuffers_lod;

        SKVManager &skvManager = SKVManager::getInstance();
};


#endif //XENFRAMEWORK_KERNEL_H
