#include "new.h"

void *new(const void *_class, ...)
{

    const struct Class *class = _class;
    const void *p = calloc(1, class->size);

    if(!p) {return NULL;}

    *(const struct Class **) p = class;

    if (class->ctor) {

        va_list ap;

        va_start(ap, _class);
        p = class->ctor(p, &ap);
        va_end(ap);

    }

    return p;

}

void delete(void *self)
{

    const struct Class **cp = self;

    if (self && *cp && (*cp)->dtor) {
        self = (*cp)->dtor(self);
    }

    memset(self, 0x00, (*cp)->size);
    free(self);

}

int add(const void *self, ...)
{

    const struct Class * const * cp = self;

    if (self && *cp && (*cp)->add) {

        va_list ap;

        va_start(ap, self);
        (*cp)->add(self, &ap);

        va_end(ap);

    }

    return 0;

}

void *clone(const void *self)
{

    const struct Class * const * cp = self;

    if (self && *cp && (*cp)->clone) {
        return (*cp)->clone(self);
    }

    return NULL;

}

int differ(const void *self, const void *b)
{

    const struct Class * const * cp = self;

    if (self && *cp && (*cp)->clone) {
        return (*cp)->differ(self, b);
    }

    return -1;

}

size_t sizeOf(const void *self)
{

    const struct Class * const * cp = self;

    if (self && *cp) {
        return (*cp)->size;
    }

    return -1;

}
