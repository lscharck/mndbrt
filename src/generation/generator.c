#include "adds.h"

void *genset(void *info)
{

    double x1 = ((genset_pack*)info)->x1;
    double y1 = ((genset_pack*)info)->y1;
    double xscale = ((genset_pack*)info)->xscale;
    double yscale = ((genset_pack*)info)->yscale;
    uint8_t *image = ((genset_pack*)info)->image;
    uint16_t width = ((genset_pack*)info)->width;
    uint16_t height = ((genset_pack*)info)->height;
    uint8_t thread_idx = ((genset_pack*)info)->thread_no;

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
