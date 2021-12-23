#ifndef DEV_H
#define DEV_H

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <inttypes.h>
#include <complex.h>
#include <strings.h>
#include <fcntl.h>
#define MAXINTER 2048
#define CHANNEL 3
#define THRES 2
#define HDRLEN 18
#define UPPER 100000

typedef struct
{
    double x1;
    double y1;
    double x2;
    double y2;

    uint16_t width;
    uint16_t height;
}dim;

void setup(int argc, char **argv, dim *dimensions);

void error(const char *msg) __attribute__((noreturn));

void genset(dim *dimensions, uint8_t *image);

void put_color(uint8_t *image, double pixel_scale, uint16_t n, double complex z, double complex dz);

void fio(dim *dimensions);

#endif // DEV_H
