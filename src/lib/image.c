#include "image.h"

struct Image
{
    const void *class;
    const void *image;
    uint32_t indx;
    uint16_t width;
    uint16_t height;
    uint8_t thread_no;
};

static const struct Class _Image = {
    sizeof(struct Image),
    image_ctor, image_dtor,
    image_clone, image_add,
    image_differ
};

const void *Image = &_Image;

void *image_info = NULL;

static void *image_ctor(void *_self, va_list *app)
{

    struct Image *self = _self;
    struct image_t **image_p = (struct image_t**)&image_info;

    self->thread_no = (uint8_t)va_arg(*app, int);
    uint16_t width = self->width = (uint16_t)va_arg(*app, int);
    uint16_t height = self->height = (uint16_t)va_arg(*app, int);
    self->indx = self->thread_no * width * 3;

    if (!image_info) {
        image_fio(image_p, width, height);
    }

    self->image = (*image_p)->image;
    ++(*image_p)->cnt;

    return self;

}

static void *image_dtor(void *_self)
{

    struct Image *self = _self;
    struct image_t *image_p = image_info;

    if (--image_p->cnt == 0) {
        msync(image_p->image, image_p->size, MS_SYNC);
        munmap(image_p->image, image_p->size);
        close(image_p->f);
    }

    return self;

}

static int image_add(const void *_self, va_list *app)
{

    const struct Image *self = _self;
    uint32_t idx = self->indx;
    uint8_t *image_p = (uint8_t*)self->image;

    image_p[idx] = (uint8_t)va_arg(*app, int);
    image_p[idx + 1] = (uint8_t)va_arg(*app, int);
    image_p[idx + 2] = (uint8_t)va_arg(*app, int);

    return 0;

}

static void *image_clone(const void *_self)
{
    return NULL;
}

static int image_differ(const void *_self, const void *_b)
{
    return 0;
}
