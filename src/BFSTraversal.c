#include "BFSTraversal.h"
#include "TraversalArray.h"
#include "Validations.h"

static void BFSTraversal(char symbol, Matrix* matrix, Vector* vector, char newSymbol)
{
    int row = 0;
    int col = 0;

    for (int i = 0; i < vector->size; i++)
    {
        row = vector->elements[vector->outputIndex].row;
        col = vector->elements[vector->outputIndex].col;

        if (validateField(row - 1, col, matrix->rows, matrix->cols, matrix->lines, symbol))
        {
            addElement(vector, row - 1, col);
            matrix->lines[row - 1][col] = newSymbol;
        }
        if (validateField(row, col + 1, matrix->rows, matrix->cols, matrix->lines, symbol))
        {
            addElement(vector, row, col + 1);
            matrix->lines[row][col + 1] = newSymbol;
        }
        if (validateField(row + 1, col, matrix->rows, matrix->cols, matrix->lines, symbol))
        {
            addElement(vector, row + 1, col);
            matrix->lines[row + 1][col] = newSymbol;
        }
        if (validateField(row, col - 1, matrix->rows, matrix->cols, matrix->lines, symbol))
        {
            addElement(vector, row, col - 1);
            matrix->lines[row][col - 1] = newSymbol;
        }
        increaseOutputIndex(vector);
    }
}

static int setCapacity(int rows, int cols)
{
    if (rows > cols)
    {
        return (cols + CHASING_INDEX);
    }
    
    return (rows + CHASING_INDEX);
}

int findLongestLineWithBFS(Matrix* matrix)
{
    Vector vector;
    int capacity = setCapacity(matrix->rows, matrix->cols);
    initVector(&vector, capacity);
    char symbol = '0';
    char newSymbol = '0';

    for (int row = 0; row < matrix->rows; row++)
    {
        for (int col = 0; col < matrix->cols; col++)
        {   
            symbol = matrix->lines[row][col];

            if (validateColor(symbol))
            {
                newSymbol = symbol + LOWER_CASE_INDEX;
                matrix->lines[row][col] = newSymbol;
                addElement(&vector, row, col);
                BFSTraversal(symbol, matrix, &vector, newSymbol);
                setLongestLine(matrix, vector.size);
                resetVector(&vector);
            }
        }
    }

    deinitVector(&vector);
    return matrix->longestLine;
}