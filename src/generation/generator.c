#include "adds.h"

void genset(dim *dimensions, uint8_t *image)
{

    uint16_t width, height, cnt;
    double x1, y1, x2, y2, xscale, yscale;
    double complex z, dz;

    width = dimensions->width;
    height = dimensions->height;

    x1 = dimensions->x1;
    y1 = dimensions->y1;
    x2 = dimensions->x2;
    y2 = dimensions->y2;

    xscale = (x2 - x1) / (width - 1);
    yscale = (y2 - y1) / (height - 1);

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x++) {

            cnt = 0;
            z = dz = CMPLX(0.0, 0.0);

            while (cabs(z) < THRES && cnt < MAXINTER) {
                dz = 2 * z * dz + 1;
                z = cpow(z,CMPLX(2.0,0.0)) + CMPLX(x1 + (x * xscale), y1 + (y * yscale));
                cnt++;
            }

            put_color(image, fabs(xscale), cnt, z, dz);

        }

    }

}
