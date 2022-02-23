#include "adds.h"

int main(int argc, char **argv)
{

    //TODO add more color pallets, improve algorithms, vectors

    //create dim_t struct on stack
    dim_t dimensions;

    // pass args and dimensions to input checker and assign
    setup(argc, argv, &dimensions);

    // pass dimensions to thread dispatch function
    dispatch(&dimensions);

}
