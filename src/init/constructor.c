#include "adds.h"

void setup(int argc, char **argv, dim *dimensions)
{

    if (argc != 7) {
        error("Not enough inputs!");
    }

    dimensions->width = (uint16_t)atof(argv[1]);
    dimensions->height = (uint16_t)atof(argv[2]);

    dimensions->x1 = atof(argv[3]);
    dimensions->y1 = atof(argv[4]);
    dimensions->x2 = atof(argv[5]);
    dimensions->y2 = atof(argv[6]);

}
