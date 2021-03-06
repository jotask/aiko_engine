
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

#include <future>
#include <iostream>

void called_from_async()
{
    std::cout << "Async call" << std::endl;
}

int maino()
{
    //called_from_async launched in a separate thread if possible
    std::future<void> result(std::async(called_from_async));

    std::cout << "Message from main." << std::endl;

    //ensure that called_from_async is launched synchronously
    //if it wasn't already launched
    result.get();

    return EXIT_SUCCESS;

}