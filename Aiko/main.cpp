
#include "src/constants.h"

#include <iostream>
#include <ctime>

#include "src/engine/aiko.h"

int main(int argc, char ** argv)
{

    srand(static_cast<unsigned int>(time(nullptr)));

    aiko::Aiko aiko;
    
    aiko.run();

    return EXIT_SUCCESS;

}