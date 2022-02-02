#ifndef NEW_H
#define NEW_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "types.h"

void *new(const void *type, ...);

void delete(void *item);

int add(void *self, ...);

void *clone(const void *self);

int differ(const void *self, const void *b);

size_t sizeOf(const void *self);

#endif // NEW_H
