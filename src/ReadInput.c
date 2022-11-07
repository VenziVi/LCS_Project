#include "ReadInput.h"
#include <stdio.h>
#include <stdlib.h>

static void setInputData(FILE* fPtr, Matrix* matrix)
{
    int rows = 0;
    int cols = 0;

    fscanf(fPtr, "%d %d", &rows, &cols);

    initMatrix(matrix, rows, cols);
    
    for (int row = 0; row < matrix->rows; row++)
    {
        for (int col = 0; col < matrix->cols; col++)
        {
            fscanf(fPtr, " %c", &matrix->lines[row][col]);
        }
    } 
}

bool readInputData(char* filePath, Matrix* matrix)
{
    FILE* fPtr = fopen(filePath, "r");

    if (fPtr == NULL)
    {
        return false;
    }

    setInputData(fPtr, matrix);

    fclose(fPtr);
    return true;
}