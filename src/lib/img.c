#include "image.h"

void image_fio(struct image_t **image_info, uint16_t width, uint16_t height)
{

    int f;
    uint8_t *img;
    uint32_t size, header_size;
    char *header = calloc(1, sizeof(char) * HDRLEN);
    const char *path = "/Users/lukescharck/Documents/output.ppm";

    snprintf(header, HDRLEN, "P6\n%hd %hd 255\n", width, height);
    header_size = strnlen(header, HDRLEN);

    size = width * height * 3 + header_size;

    f = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (f < 0) {printf("Error opening out file\n");}

    img = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    if (ftruncate(f, size) < 0) {printf("Error extending file\n");}

    strncpy((char*)img, header, HDRLEN);

    *image_info = calloc(1, sizeof(struct image_t));
    (*image_info)->image = img + header_size;
    (*image_info)->size = size;
    (*image_info)->f = f;
    (*image_info)->cnt = 0;

}
