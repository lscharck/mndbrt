#include "adds.h"

void put_color(uint8_t *image, uint16_t cnt, uint32_t idx, coloring_schem color_func)
{
    color_func(image, cnt, idx);
}

void pcwise(uint8_t *image, uint16_t cnt, uint32_t idx)
{

    double n, half = MAXINTER / 2.0;

    // assign to image
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
        image[idx] = 255 * fmin(fmax(0.6118 * pow(n, 3) - 0.2286 * pow(n, 2)
                - 01.3475 * n + 0.9493, 0), 1);
        image[idx + 1] = 255 * fmin(fmax(0.3465 * pow(n, 4) - 4.646 * pow(n, 3)
                + 4.1957 * pow(n, 2) - 0.5881 * n + 0.8365, 0), 1);
        image[idx + 2] = 255 * fmin(fmax(-36.6545 * pow(n, 4) + 70.2973 * pow(n, 3)
                - 40.0717 * pow(n, 2) + 6.8002 * n - 0.0272, 0), 1);
    }

}

void trig(uint8_t *image, uint16_t n, uint32_t idx)
{

    float a = 0.1f;
    double r, g, b;

    r = 0.5f * sin(a * n) + 0.5f;
    g = 0.5f * sin(a * n + 2.094f) + 0.5f;
    b = 0.5f * sin(a * n + 4.188f) + 0.5f;

    // assign to image
    image[idx] = (uint8_t)(r * 255) % 255;
    image[idx + 1] = (uint8_t)(g * 255) % 255;
    image[idx + 2] = (uint8_t)(b * 255) % 255;

}
