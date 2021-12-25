#ifndef DEV_H
#define DEV_H

#include <complex.h>
#include <fcntl.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>
#define MAXINTER 2048
#define ESCAPE 2
#define CHANNEL 3
#define HDRLEN 18
#define UPPER 100000
#define TIME 1000000000.0
typedef void (*conversion)(char *, void *);

typedef struct
{
    double x1;
    double y1;
    double x2;
    double y2;

    uint16_t width;
    uint16_t height;
}dim;

void convd(char *src, void *dst);

void convl(char *src, void *dst);

void error(const char *msg) __attribute__((noreturn));

void error_check(char *src, void *dst, void (*conv) (char *, void *));

void fio(dim *dimensions);

void genset(dim *dimensions, uint8_t *image);

void put_color(uint8_t *image, double pixel_scale, uint16_t n, double complex z, double complex dz);

void setup(int argc, char **argv, dim *dimensions);

#endif // DEV_H
