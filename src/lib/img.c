#include "image.h"

void *image_fio(uint16_t width, uint16_t height)
{

    int f;
    uint8_t *img;
    uint32_t size, h_size;
    struct image_info *image = NULL;
    const char *path = "/Users/lukescharck/Documents/output.ppm";
    char *header = calloc(1, sizeof(char) * HDRLEN);

    snprintf(header, HDRLEN, "P6\n%hd %hd 255\n", width, height);
    h_size = strnlen(header, HDRLEN);

    size = width * height * 3 + h_size;

    f = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (f < 0) {printf("Error opening out file\n");}
    img = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    if (ftruncate(f, size) < 0) {printf("Error extending file\n");}

    strncpy((char*)img, header, HDRLEN);

    image = calloc(1, sizeof(struct image_info));
    image->image = img + h_size;
    image->size = size;
    image->f = f;
    image->cnt = 0;

    return image;

    //dispatch(dimensions, img + h_size);

}
