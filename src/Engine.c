#include "Engine.h"
#include "ReadInput.h"
#include "DFSTraversal.h"
#include "BFSTraversal.h"
#include <stdio.h>

void proceed(char* filePath, Matrix* matrix)
{
    int result = 0;

    if (!readInputData(filePath, matrix))
    {
        printf("Incorect file path!\n");
        return;
    }

    if(matrix->rows <= 200 && matrix->cols <= 200)
    {
        result = findLongestLineWithDFS(matrix);
    }
    else
    {
        result = findLongestLineWithBFS(matrix);
    }

    printf("%d \n", result);
}