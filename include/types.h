#ifndef NEW_R
#define NEW_R

#include <stdlib.h>
#include <stdarg.h>

struct Class
{
    size_t size;
    void * (*ctor) (void *self, va_list *app);
    void * (*dtor) (void *self);
    void * (*clone) (const void *self);
    int (*add) (void *self, va_list *app);
    int (*differ) (const void *self, const void *b);
};

#endif // NEW_R
