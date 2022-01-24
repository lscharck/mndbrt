#ifndef DEV_H
#define DEV_H

#include <complex.h>
#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "new.h"
#define MAXINTER 2048
#define ESCAPE 2
#define CHANNEL 3
#define UPPER 100000
#define TIME 1000000000.0
#define MAXTHREAD 8
typedef void (*conversion)(char *, void *);

typedef struct
{
    double x1;
    double y1;
    double x2;
    double y2;

    uint16_t width;
    uint16_t height;
}dim_t;

typedef struct
{
    double x1;
    double y1;
    double xscale;
    double yscale;
    pthread_mutex_t *lock;
    uint16_t width;
    uint16_t height;
    uint8_t thread_no;
}genset_t;

void convd(char *src, void *dst);

void convl(char *src, void *dst);

void dispatch(dim_t *dimensions);

void error(const char *msg) __attribute__((noreturn));

void error_check(char *src, void *dst, void (*conv) (char *, void *));

void *genset(void *info);

void put_color(void *a, double pixel_scale, uint16_t n, double complex z, double complex dz, uint32_t idx);

void setup(int argc, char **argv, dim_t *dimensions);

#endif // DEV_H
