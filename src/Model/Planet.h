//
// Created by Xenoth on 16/07/2017.
//

#ifndef XENFRAMEWORK_PLANET_H
#define XENFRAMEWORK_PLANET_H


#include <string>

class Planet
{
    public:
        inline Planet(std::string name) { this->name = name; };

    private:
        std::string name;
};


#endif //XENFRAMEWORK_PLANET_H
