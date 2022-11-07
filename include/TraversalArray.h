#ifndef TRAVERSAL_ARRAY_H_
#define TRAVERSAL_ARRAY_H_

#define CHASING_INDEX 3

typedef struct
{
    int row;
    int col;
} Element;

typedef struct 
{
    Element* elements;
    int inputIndex;
    int outputIndex;
    int size;
    int capacity;
} Vector;

void initVector(Vector* vector, int capacity);
void addElement(Vector* vector, int row, int col);
void resetVector(Vector* vector);
void increaseInputIndex(Vector* vector);
void increaseOutputIndex(Vector* vector);
void checkInputIndex(Vector* vector);
void deinitVector(Vector* vector);

#endif //TRAVERSAL_ARRAY_H_