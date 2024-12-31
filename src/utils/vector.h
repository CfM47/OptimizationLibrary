#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int *data;
  size_t size;
  size_t capacity;
} Vector_i;

void initVector(Vector_i *vec, size_t initialCapacity);
void initVectorDefault(Vector_i *vec);
void resizeVector(Vector_i *vec, size_t newCapacity);
void pushBack(Vector_i *vec, int value);
int getElementAt(Vector_i *vec, size_t index);
int deleteAt(Vector_i *vec, size_t index);
void freeVector(Vector_i *vec);

#endif