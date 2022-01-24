#include "adds.h"

void dispatch(dim_t *dimensions)
{

    uint16_t width, height;
    double x1, y1, x2, y2;
    double xscale, yscale;
    double cpu_time = 0.0;

    genset_t index[MAXTHREAD];
    pthread_t threads[MAXTHREAD];
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
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

    for (uint8_t i = 0; i < MAXTHREAD; i++) {

        index[i].x1 = x1;
        index[i].y1 = y1;
        index[i].xscale = xscale;
        index[i].yscale = yscale;
        index[i].lock = &lock;
        index[i].width = width;
        index[i].height = height;
        index[i].thread_no = i;

        if (pthread_create(&threads[i], NULL, genset, (void*)&index[i]) != 0) {
            perror("Error in creating thread");
        }

    }

    for (uint8_t i = 0; i < MAXTHREAD; i++) {

        pthread_join(threads[i], NULL);

    }

    clock_gettime(CLOCK_MONOTONIC, &finish);

    cpu_time = (finish.tv_sec - start.tv_sec);
    cpu_time += (finish.tv_nsec - start.tv_nsec) / TIME;

    printf("CPU Time: %f seconds", cpu_time);

    pthread_mutex_destroy(&lock);

}
