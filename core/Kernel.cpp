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
    std::cout << "texture_lod = " << skvManager.getValue(CONFIG_PATH, "textures_lod") << std::endl;
    std::cout << "shaders_lod = " << skvManager.getValue(CONFIG_PATH, "shaders_lod") << std::endl;
    std::cout << "fonts_lod = " << skvManager.getValue(CONFIG_PATH, "fonts_lod") << std::endl;
    std::cout << "sound_buffers_lod = " << skvManager.getValue(CONFIG_PATH, "sound_buffers_lod") << std::endl;

    textures_lod = skvManager.getValue(CONFIG_PATH, "textures_lod");
    shaders_lod = skvManager.getValue(CONFIG_PATH, "shaders_lod");
    fonts_lod = skvManager.getValue(CONFIG_PATH, "fonts_lod");
    soundBuffers_lod = skvManager.getValue(CONFIG_PATH, "sound_buffers_lod");
}

void Kernel::initHandlers()
{
    std::cout << "Reading config file..." << std::endl;
    readConfigFile();

    AssetsLoader assetsLoader;

    std::map<std::string, sf::Texture*> textures = assetsLoader.loadTextures(textures_lod);
    std::map<std::string, sf::Font*> fonts = assetsLoader.loadFonts(fonts_lod);
    std::map<std::string, sf::Shader*> shaders = assetsLoader.loadShaders(shaders_lod);
    std::map<std::string, sf::SoundBuffer*> soundBuffers = assetsLoader.loadSoundBuffers(soundBuffers_lod);
}