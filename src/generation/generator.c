#include "adds.h"

void genset(dim *dimensions, uint8_t *image)
{

    uint16_t width, height, cnt;
    uint32_t idx = 0;
    double x1, y1, x2, y2, xscale, yscale, scale, n, half = MAXINTER / 2.0;
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

            if (cnt == MAXINTER) {
                image[idx] = 0;
                image[idx + 1] = 0;
                image[idx + 2] = 0;
            }
            else if (cnt < half) {
                image[idx] = 255 * fmin(fmax(0.1067 * (cnt / half) + 0.92, 0), 1);
                image[idx + 1] = 255 * fmin(fmax(0.5584 * (cnt / half) + 0.2494, 0), 1);
                image[idx + 2] = 255 * fmin(fmax(-0.0376 * (cnt / half) + 0.0282, 0), 1);
            }
            else {
                n = (cnt - half) / half;
                image[idx] = 255 * fmax(0.7059 * pow(n, 3) - 1.1513 * pow(n, 2)
                        - 0.6120 * n + 1.0268, 0);
                image[idx + 1] = 255 * fmax(-9.7219 * pow(n, 4) + 14.7144 * pow(n, 3)
                        - 7.1107 * pow(n, 2) + 1.2479 * n + 0.8593, 0);
                image[idx + 2] = 255 * fmax(-25.3733 * pow(n, 4) + 49.1936 * pow(n, 3)
                        - 28.0684 * pow(n, 2) + 4.8988 * n - 0.0501, 0);
            }

            idx+=3;

        }

    }

}
