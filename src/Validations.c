#include "Validations.h"

bool validateColor(char symbol)
{
    if (symbol == 'R' || symbol == 'G' || symbol == 'B')
    {
        return true;
    }

    return false;
}

bool validateField(int row, int col, int rows, int cols, char** matrix, char symbol)
{
    if (col < 0 || row < 0 || row >= rows || col >= cols)
    {
        return false;
    }

    if (matrix[row][col] != symbol)
    {
        return false;
    }
    
    return true;
}