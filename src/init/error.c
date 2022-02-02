#include "adds.h"

void error(const char *msg)
{

    // print error msg and terminate
    perror(msg);
    exit(EXIT_FAILURE);

}
