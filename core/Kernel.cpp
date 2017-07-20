//
// Created by Xenoth on 16/07/2017.
//

#include "Kernel.h"

void Kernel::initKernel()
{
    initHandlers();
}

void Kernel::readConfigFile()
{
    textures_lod = skvManager.getValue(CONFIG_PATH, "textures_lod");
    shaders_lod = skvManager.getValue(CONFIG_PATH, "shaders_lod");
    fonts_lod = skvManager.getValue(CONFIG_PATH, "fonts_lod");
    soundBuffers_lod = skvManager.getValue(CONFIG_PATH, "sound_buffer_lod");
}

void Kernel::initHandlers()
{
    readConfigFile();

    AssetsLoader assetsLoader;
    std::map<std::string, sf::Texture*> textures = assetsLoader.loadTextures(textures_lod);
}