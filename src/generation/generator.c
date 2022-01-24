#include "adds.h"

void *genset(void *info)
{

    genset_t *info_p = info;

    double x1 = info_p->x1;
    double y1 = info_p->y1;
    double xscale = info_p->xscale;
    double yscale = info_p->yscale;
    uint8_t *image = info_p->image;
    uint16_t width = info_p->width;
    uint16_t height = info_p->height;
    uint8_t thread_idx = info_p->thread_no;

    uint16_t cnt;
    uint32_t image_idx;
    double complex z, dz, c;

    for (uint16_t y = thread_idx; y < height; y+=MAXTHREAD) {

        image_idx = y * width * 3;

        for (uint16_t x = 0; x < width; x++) {

            cnt = 0;
            c = CMPLX(x1 + (x * xscale), y1 + (y * yscale));
            z = dz = CMPLX(0.0, 0.0);

            while (cabs(z) < ESCAPE && cnt < MAXINTER) {
                dz = (2 * z * dz) + 1;
                z = (z * z) + c;
                cnt++;
            }

            put_color(image, xscale, cnt, z, dz, image_idx);

            image_idx+=3;

        }

    }

    return NULL;

}
