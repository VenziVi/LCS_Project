#include "TraversalArray.h"
#include <stdlib.h>

void initVector(Vector* vector, int capacity)
{
    vector->capacity = capacity;
    vector->size = 0;
    vector->inputIndex = 0;
    vector->outputIndex = 0;
    vector->elements = malloc(sizeof(Element) * vector->capacity);
}

void addElement(Vector* vector, int row, int col)
{
    Element element;
    element.row = row;
    element.col = col;

    vector->elements[vector->inputIndex] = element;
    increaseInputIndex(vector);
}

void resetVector(Vector* vector)
{
    vector->inputIndex = 0;
    vector->outputIndex = 0;
    vector->size = 0;
}

void increaseInputIndex(Vector* vector)
{
    vector->inputIndex++;
    vector->size++;

    if (vector->inputIndex == (vector->capacity - 1))
    {
        vector->inputIndex = 0;
    }
}

void increaseOutputIndex(Vector* vector)
{
    vector->outputIndex++;

    if (vector->outputIndex == (vector->capacity - 1))
    {
        vector->outputIndex = 0;
    }
}

void deinitVector(Vector* vector)
{
    free(vector->elements);
}