#include "Matrix.h"
#include "Engine.h"
#include <stdlib.h>

int main(int argc, char** argsv)
{
    Matrix matrix;

    for (int i = 1; i < argc; i++)
    {
        proceed(argsv[i], &matrix);
        deinitMatrix(&matrix);
    }

    return EXIT_SUCCESS;
}