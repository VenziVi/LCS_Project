#include "Matrix.h"
#include <stdlib.h>

void initMatrix(Matrix* matrix, int rows, int cols)
{
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->longestLine = 0;

    matrix->lines = (char**)malloc(sizeof(char*) * matrix->rows);
    
    for (int i = 0; i < matrix->rows; i++)
    {
        matrix->lines[i] = (char*)malloc(sizeof(char) * matrix->cols);
    }
}

void setLongestLine(Matrix* matrix, int newLineSize)
{
    if (matrix->longestLine < newLineSize)
    {
        matrix->longestLine = newLineSize;
    }  
}

void deinitMatrix(Matrix* matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        free(matrix->lines[i]);
    }
    free(matrix->lines);
}