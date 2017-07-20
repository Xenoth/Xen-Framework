//
// Created by Xenoth on 19/07/2017.
//

#ifndef XENFRAMEWORK_ASSETSLOADER_H
#define XENFRAMEWORK_ASSETSLOADER_H

#include "AbstractLoader.h"

#include <map>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class AssetsLoader : public AbstractLoader
{
    public:
        std::map<std::string,sf::Texture*> loadTextures(std::string texturesLodFilePath);
        std::map<std::string,sf::Font*> loadFonts(std::string fontsLodFilePath);
        std::map<std::string,sf::Shader*> loadShaders(std::string shadersLodFilePath);
        std::map<std::string,sf::SoundBuffer*> loadSoundBuffers(std::string soudBufferLodFilePath);

};


#endif //XENFRAMEWORK_ASSETSLOADER_H
