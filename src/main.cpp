//
// Created by Xenoth on 20/07/2017.
//

#include "../core/Kernel.h"

int main(int argc, char** argv)
{
    std::cout << "Booting Kernel..." << std::endl;

    Kernel kernel;
    kernel.initKernel();

    std::cout << "Kernel Ready." << std::endl;
    return 0;
}