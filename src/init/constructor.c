#include "adds.h"

void setup(int argc, char **argv, dim_t *dimensions)
{

    if (argc != 7) {
        error("Usage: mndbrt w h x1 y1 x2 y2");
    }

    error_check(argv[1], &(dimensions->width), convl);
    error_check(argv[2], &(dimensions->height), convl);

    error_check(argv[3], &(dimensions->x1), convd);
    error_check(argv[4], &(dimensions->y1), convd);
    error_check(argv[5], &(dimensions->x2), convd);
    error_check(argv[6], &(dimensions->y2), convd);

    if (dimensions->x1 >= dimensions->x2 || dimensions->y2 >= dimensions->y1) {
        error("Improper bounding box");
    }

}

void error_check(char *src, void *dst, conversion conv)
{

    conv(src, dst);

}

void convl(char *src, void *dst)
{
    char *endptr = NULL;
    int base = 10;
    long n;
    uint16_t *dest = dst;

    n = strtol(src, &endptr, base);

    if (n == 0 && endptr == src) {
        // check if strtol worked
        error("Invalid Input(s)");
    }
    else if (n == LONG_MIN || n == LONG_MAX) {
        //  check for underflow or overflow
        error("Dimension out of spec");
    }
    else if (*endptr != '\0') {
        // check for invalid chars
        error("Invalid characters");
    }
    else if (n <= 0) {
        // check for negatives
        error("Negative dimensions");
    }
    else if ((uint16_t)n != n) {
        // check if it fits in 16 bits
        error("Dimensions out of spec");
    }

    *dest = n;

}

void convd(char *src, void *dst)
{
    char *endptr = NULL;
    double n;
    double *dest = dst;

    n = strtod(src, &endptr);

    if (n == 0 && endptr == src) {
        // check if strtod worked
        error("Invalid Input(s)");
    }
    else if (n == HUGE_VAL || n == HUGE_VALF || n == HUGE_VALL) {
        //  check for underflow or overflow
        error("Coords out of spec");
    }
    else if (*endptr != '\0') {
        // check for invalid chars
        error("Invalid characters");
    }

    *dest = n;

}
