#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

#include "Matrix.h"
#include <stdbool.h>

bool validateColor(char symbol);
bool validateField(int row, int col, int rows, int cols, char** matrix, char symbol);

#endif //VALIDATIONS_H_