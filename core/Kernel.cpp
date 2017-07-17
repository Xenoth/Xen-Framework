//
// Created by Xenoth on 16/07/2017.
//

#include "Kernel.h"

Kernel::Kernel()
{
    TexturesLoader texturesLoader = TexturesLoader(CONFIG_PATH+TEXTURES_LOD);
    this->texturesHandler = TexturesHandler(texturesLoader);
}
