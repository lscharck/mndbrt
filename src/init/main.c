#include "adds.h"

int main(int argc, char **argv)
{

    //TODO add more color pallets, improve algorithms, vectors

    dim_t dimensions;

    setup(argc, argv, &dimensions);

    dispatch(&dimensions);

}
