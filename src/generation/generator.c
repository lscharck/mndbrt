#include "adds.h"

void genset(dim *dimensions, uint8_t *image)
{

    uint16_t width, height, cnt;
    double x1, y1, x2, y2, xscale, yscale;
    double complex z, dz, c;
    double cpu_time = 0.0;

    struct timespec start, finish;

    width = dimensions->width;
    height = dimensions->height;

    x1 = dimensions->x1;
    y1 = dimensions->y1;
    x2 = dimensions->x2;
    y2 = dimensions->y2;

    xscale = (x2 - x1) / (width - 1);
    yscale = (y2 - y1) / (height - 1);

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x++) {

            cnt = 0;
            c = CMPLX(x1 + (x * xscale), y1 + (y * yscale));
            z = dz = CMPLX(0.0, 0.0);

            while (cabs(z) < ESCAPE && cnt < MAXINTER) {
                dz = (2 * z * dz) + 1;
                z = (z * z) + c;
                cnt++;
            }

            put_color(image, xscale, cnt, z, dz);

        }

    }

    clock_gettime(CLOCK_MONOTONIC, &finish);

    cpu_time = (finish.tv_sec - start.tv_sec);
    cpu_time += (finish.tv_nsec - start.tv_nsec) / TIME;

    printf("CPU Time: %f seconds", cpu_time);

}
