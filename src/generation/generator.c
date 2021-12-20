#include "adds.h"

void genset(dim *dimensions, uint8_t *image)
{

    uint16_t width, height, cnt;
    uint32_t idx = 0;
    double x1, y1, x2, y2, xscale, yscale, scale;
    double complex z;

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
            z = CMPLX(0.0, 0.0);

            while (cabs(z) < THRES && cnt < MAXINTER) {
                z = cpow(z,CMPLX(2.0,0.0)) + CMPLX(x1 + (x * xscale), y1 + (y * yscale));
                cnt++;
            }

            //scale = cnt + 1 - log10(log2(cabs(z)));
            //scale = (double)cnt / MAXINTER;
            //if (scale > 1) printf("scale: %f", scale);

            if (cnt == MAXINTER) {
                image[idx] = 0;
                image[idx + 1] = 0;
                image[idx + 2] = 0;
            }
            else if (cnt < (MAXINTER / 2)) {
                image[idx + 2] = 255 * 2 * cnt / MAXINTER;
                image[idx] = image[idx + 1] = 0;
            }
            else {
                image[idx + 2] = 255;
                image[idx] = image[idx + 1] = 255 * 2 * (cnt - (MAXINTER / 2)) / MAXINTER;
            }

            idx+=3;

        }

    }

}
