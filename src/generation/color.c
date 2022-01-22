#include "adds.h"

void put_color(void *a, double pixel_spacing, uint16_t n, double complex z, double complex dz, uint32_t idx)
{

    double D, dwell, finalrad, finalang;
    double dscale, value, P;
    double angle, radius;
    double hue, saturation;
    double C, X, m, H_p;
    double r, g, b;

    // dwell
    D = n + log2(log2(cabs(z)));
    dwell = floor(D);
    finalrad = D - floor(D);
    finalang = carg(z);

    // inital check for thres
    if (dwell >= MAXINTER) {
        //image[idx] = 255;
        //image[idx + 1] = 255;
        //image[idx + 2] = 255;
        add(a, 255, 255, 255);
        return;
    }

    // distance est
    dscale = log2((log10(pow(cabs(z), 2)) * cabs(z) / cabs(dz)) / pixel_spacing);

    // scaled distance to a brightness
    if (dscale > 0) {
        value = 1.0;
    }
    else if (dscale > -8) {
        value = (8 + dscale) / 8;
    }
    else {
        value = 0.0;
    }

    // log scaling to thres
    P = log10(dwell) / log10(UPPER);

    // remap angle and radius onto color wheel
    if (P < 0.5) {
        P = 1.0 - 1.5 * P;
        angle = 1 - P;
        radius = sqrt(P);
    }
    else {
        P = 1.5 * P - 0.5;
        angle = P;
        radius = sqrt(P);
    }

    // make every other strip a little brighter
    if (fmod(dwell, 2.0) != 0) {
        value = 0.85 * value;
        radius = 0.667 * radius;
    }

    // break stripes into squares to give checkboard look
    if (finalang > M_PI) {
        angle = angle + 0.02;
    }

    // turn each square into a rainbow gradient
    angle = angle + 0.0001 * finalrad;

    // use 10 full rainbows
    hue = angle * 10.0;
    hue = hue - floor(hue);

    // define saturation
    saturation = radius - floor(radius);

    // convert HSV to rgb
    C = value * saturation;
    H_p = 6.0 * hue;
    X = C * (1 - fabs(fmod(H_p, 2.0) - 1));
    m = value - C;

    if (0 <= H_p && H_p < 1) {
        r = C;
        g = X;
        b = 0;
    }
    else if (1 <= H_p && H_p < 2) {
        r = X;
        g = C;
        b = 0;
    }
    else if (2 <= H_p && H_p < 3) {
        r = 0;
        g = C;
        b = X;
    }
    else if (3 <= H_p && H_p < 4) {
        r = 0;
        g = X;
        b = C;
    }
    else if (4 <= H_p && H_p < 5) {
        r = X;
        g = 0;
        b = C;
    }
    else if (5 <= H_p && H_p < 6){
        r = C;
        g = 0;
        b = X;
    }
    else {
        r = 0;
        g = 0;
        b = 0;
    }

    // assign to image
    //image[idx] = (r + m) * 255;
    //image[idx + 1] = (g + m) * 255;
    //image[idx + 2] = (b + m) * 255;
    add(a, (r + m) * 255, (g + m) * 255, (b + m) * 255);

}
