#include "DFSTraversal.h"
#include "Validations.h"

static void DFSTraversal(int row_index, int col_index, Matrix* matrix, char symbol)
{
    if (!validateField(row_index, col_index, matrix->rows, matrix->cols, matrix->lines, symbol))
    {
        return;
    }

    matrix->lines[row_index][col_index] = symbol + LOWER_CASE_INDEX;
    matrix->longestLine++;
 
    DFSTraversal(row_index, col_index + 1, matrix, symbol);
    DFSTraversal(row_index, col_index - 1, matrix, symbol);
    DFSTraversal(row_index - 1, col_index, matrix, symbol);
    DFSTraversal(row_index + 1, col_index, matrix, symbol);

}

int findLongestLineWithDFS(Matrix* matrix)
{
    int result = 0;
    char symbol = '0';

    for (int row = 0; row < matrix->rows; row++)
    {
        for (int col = 0; col < matrix->cols; col++)
        {            
            symbol = matrix->lines[row][col];

            if (validateColor(symbol))
            {
                DFSTraversal(row, col, matrix, symbol);
            }

            if (matrix->longestLine > result)
            {
                result = matrix->longestLine;
            }
            
            matrix->longestLine = 0;
        }
    }

    return result;
}