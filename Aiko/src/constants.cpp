#include "constants.h"

int random(int low, int high)
{
    const int range_from = low;
    const int range_to = high;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    return distr(generator);
}