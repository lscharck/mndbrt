#include "adds.h"

void fio(dim_t *dimensions)
{

    int f;
    uint8_t *img;
    uint16_t width, height;
    uint32_t size, h_size;

    const char *path = "/Users/lukescharck/Documents/output.ppm";
    char *header = malloc(sizeof(char) * HDRLEN);

    width = dimensions->width;
    height = dimensions->height;

    snprintf(header, HDRLEN, "P6\n%hd %hd 255\n", width, height);
    h_size = strnlen(header, HDRLEN);

    size = width * height * 3 + h_size;

    f = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (f < 0) error("Error opening out file");
    img = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    if (ftruncate(f, size) < 0) error("Error extending file");

    strncpy((char*)img, header, HDRLEN);

    dispatch(dimensions, img + h_size);

    msync(img, size, MS_SYNC);
    munmap(img, size);
    close(f);

}
