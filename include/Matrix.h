#ifndef MATRIX_H_
#define MATRIX_H_

#define LOWER_CASE_INDEX 32

typedef struct matrix
{
    char** lines;
    int rows;
    int cols;
    int longestLine;
} Matrix;

void initMatrix(Matrix* matrix, int rows, int cols);
void setLongestLine(Matrix* matrix, int newLineSize);
void deinitMatrix(Matrix* matrix);

#endif //MATRIX_H_