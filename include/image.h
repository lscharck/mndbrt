#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "types.h"
#include "new.h"
#define HDRLEN 18

struct image_t
{
    uint8_t *image;
    uint32_t size;
    int f;
    int8_t cnt;
};

extern const void *Image; // pointer to image class type

static void *image_ctor(void *self, va_list *app);

static void *image_dtor(void *self);

static int image_add(void *self, va_list *app);

static void *image_clone(const void *self);

static int image_differ(const void *self, const void *b);

void image_fio(struct image_t **image_p, uint16_t width, uint16_t height);

#endif // IMAGE_H