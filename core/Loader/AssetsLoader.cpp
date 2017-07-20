//
// Created by Xenoth on 19/07/2017.
//

#include "AssetsLoader.h"



std::map<std::string, sf::Texture*> AssetsLoader::loadTextures(std::string texturesLodFilePath)
{
    std::map<std::string, std::string> allKeysValues = skvManager.getAllKeysValues(texturesLodFilePath);
    std::map<std::string, sf::Texture*> textures;

    for(auto& couple : allKeysValues)
    {
        sf::Texture *texture = new sf::Texture();
        if(!texture->loadFromFile(couple.second))
            std::cerr << "Unable to load texture \"" << couple.first << "\" from \"" << couple.second << "\"." << std::endl;
        else
            std::cout << "Texture \"" << couple.first << "\" from \"" << couple.second << "\" loaded." << std::endl;
        textures.insert(std::pair<std::string, sf::Texture*>(couple.first, texture));
    }

    return textures;
}

std::map<std::string, sf::Font*> AssetsLoader::loadFonts(std::string fontsLodFilePath) {
    return std::map<std::string, sf::Font*>();
}

std::map<std::string, sf::Shader*> AssetsLoader::loadShaders(std::string shadersLodFilePath) {
    return std::map<std::string, sf::Shader*>();
}
std::map<std::string, sf::SoundBuffer*> AssetsLoader::loadSoundBuffers(std::string soudBufferLodFilePath) {
    return std::map<std::string, sf::SoundBuffer*>();
}
