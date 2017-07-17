//
// Created by Xenoth on 16/07/2017.
//

#ifndef XENFRAMEWORK_TEXTURESHANDLER_H
#define XENFRAMEWORK_TEXTURESHANDLER_H

#include "AbstractHandler.h"
#include "../Loader/TexturesLoader.h"
#include <SFML/Graphics.hpp>

template <typename T>
class TexturesHandler : public AbstractHandler<sf::Texture>
{
    public:
        inline TexturesHandler(TexturesLoader &loader) : AbstractHandler<T>(loader) {};
};


#endif //XENFRAMEWORK_TEXTURESHANDLER_H
