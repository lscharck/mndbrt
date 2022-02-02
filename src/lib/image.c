#include "image.h"

struct Image
{
    const void *class;
    const void *image;
    int32_t offset;
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

void *_image_info = NULL;

static void *image_ctor(void *_self, va_list *app)
{

    struct Image *self = _self;
    struct image_t **image_info = (struct image_t**)&_image_info;

    uint16_t width = self->width = (uint16_t)va_arg(*app, int);
    uint16_t height = self->height = (uint16_t)va_arg(*app, int);
    int8_t thread_idx = (int8_t)va_arg(*app, int);
    self->thread_no = (uint8_t)va_arg(*app, int);

    if (!_image_info) {
        image_fio(image_info, width, height);
    }

    self->image = (*image_info)->image;
    self->offset = (thread_idx - 1) * width * 3;
    (*image_info)->cnt++;

    printf("cnt: %i\n", (*image_info)->cnt);
    printf("offset: %i\n\n", self->offset);

    return self;

}

static void *image_dtor(void *_self)
{

    struct Image *self = _self;
    struct image_t *image_info = _image_info;

    printf("in dtor\n");
    if (--image_info->cnt == 0) {
        printf("closeing image\n");
        msync(image_info->image, image_info->size, MS_SYNC);
        munmap(image_info->image, image_info->size);
        close(image_info->f);
    }

    printf("cnt: %i\n", image_info->cnt);
    printf("offset: %i\n\n", self->offset);

    return self;

}

static int image_add(void *_self, va_list *app)
{

    struct Image *self = _self;
    uint8_t *image_p = (uint8_t*)self->image;

    //printf("offset: %i\n", self->offset);
    if ((self->offset % (3 * self->width)) == 0) {

        self->offset += 3 * self->width * (self->thread_no - 1);

    }

    image_p[self->offset++] = (uint8_t)va_arg(*app, double);
    image_p[self->offset++] = (uint8_t)va_arg(*app, double);
    image_p[self->offset++] = (uint8_t)va_arg(*app, double);

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
