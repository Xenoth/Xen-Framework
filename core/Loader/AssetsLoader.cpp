//
// Created by Xenoth on 19/07/2017.
//

#include "AssetsLoader.h"

std::map<std::string, sf::Texture*> AssetsLoader::loadTextures(std::string texturesLodFilePath)
{
    std::map<std::string, std::string> allKeysValues = skvManager.getAllKeysValues(texturesLodFilePath);

    std::cout << allKeysValues.size() << " texture(s) to load :" << std::endl;

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

std::map<std::string, sf::Font*> AssetsLoader::loadFonts(std::string fontsLodFilePath)
{
    std::map<std::string, std::string> allKeysValues = skvManager.getAllKeysValues(fontsLodFilePath);

    std::cout << allKeysValues.size() << " font(s) to load :" << std::endl;

    std::map<std::string, sf::Font*> fonts;

    for(auto& couple : allKeysValues)
    {
        sf::Font *font = new sf::Font();
        if(!font->loadFromFile(couple.second))
            std::cerr << "Unable to load font \"" << couple.first << "\" from \"" << couple.second << "\"." << std::endl;
        else
            std::cout << "Font \"" << couple.first << "\" from \"" << couple.second << "\" loaded." << std::endl;
        fonts.insert(std::pair<std::string, sf::Font*>(couple.first, font));
    }

    return fonts;
}

std::map<std::string, sf::Shader*> AssetsLoader::loadShaders(std::string shadersLodFilePath)
{
    std::map<std::string, std::string> allKeysValues = skvManager.getAllKeysValues(shadersLodFilePath);

    std::cout << allKeysValues.size() << " shader(s) to load :" << std::endl;

    std::map<std::string, sf::Shader*> shaders;

    for(auto& couple : allKeysValues)
    {
        sf::Shader *shader = new sf::Shader();
        if(!shader->loadFromFile(couple.second, sf::Shader::Vertex))
            std::cerr << "Unable to load shader \"" << couple.first << "\" from \"" << couple.second << "\"." << std::endl;
        else
            std::cout << "Shader \"" << couple.first << "\" from \"" << couple.second << "\" loaded." << std::endl;
        shaders.insert(std::pair<std::string, sf::Shader*>(couple.first, shader));
    }

    return shaders;
}
std::map<std::string, sf::SoundBuffer*> AssetsLoader::loadSoundBuffers(std::string soundBufferLodFilePath)
{
    std::map<std::string, std::string> allKeysValues = skvManager.getAllKeysValues(soundBufferLodFilePath);

    std::cout << allKeysValues.size() << " soundBuffers(s) to load :" << std::endl;

    std::map<std::string, sf::SoundBuffer*> soundBuffers;

    for(auto& couple : allKeysValues)
    {
        sf::SoundBuffer *soundBuffer = new sf::SoundBuffer();
        if(!soundBuffer->loadFromFile(couple.second))
            std::cerr << "Unable to load soundBuffer \"" << couple.first << "\" from \"" << couple.second << "\"." << std::endl;
        else
            std::cout << "SoundBuffer \"" << couple.first << "\" from \"" << couple.second << "\" loaded." << std::endl;
        soundBuffers.insert(std::pair<std::string, sf::SoundBuffer*>(couple.first, soundBuffer));
    }

    return soundBuffers;
}
