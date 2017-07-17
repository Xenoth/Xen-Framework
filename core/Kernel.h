//
// Created by Xenoth on 16/07/2017.
//

#ifndef XENFRAMEWORK_KERNEL_H
#define XENFRAMEWORK_KERNEL_H

#include "Handler/TexturesHandler.h"

class Kernel
{
    public :

        const std::string CONFIG_PATH= "../config/";
        const std::string TEXTURES_LOD = "textures.lod";

        Kernel();

        TexturesHandler texturesHandler;


};


#endif //XENFRAMEWORK_KERNEL_H
