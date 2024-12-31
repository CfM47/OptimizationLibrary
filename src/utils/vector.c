#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *data;
  size_t size;
  size_t capacity;
} Vector_i;

void initVector(Vector_i *vec, size_t initialCapacity)
{
  vec->data = (int *)malloc(initialCapacity * sizeof(int));
  vec->size = 0;
  vec->capacity = initialCapacity;
}

void initVectorDefault(Vector_i *vec)
{
  initVector(vec, 4);
}

void resizeVector(Vector_i *vec, size_t newCapacity)
{
  vec->data = (int *)realloc(vec->data, newCapacity * sizeof(int));
  vec->capacity = newCapacity;
}

void pushBack(Vector_i *vec, int value)
{
  if (vec->size == vec->capacity)
  {
    if (vec->capacity == 0)
    {
      resizeVector(vec, 1);
    }
    else
    {
      resizeVector(vec, vec->capacity * 2);
    }
  }
  vec->data[vec->size++] = value;
}

int getElementAt(Vector_i *vec, size_t index)
{
  if (index >= vec->size)
  {
    fprintf(stderr, "Index out of bounds\n");
    exit(1);
  }
  return vec->data[index];
}

int deleteAt(Vector_i *vec, size_t index)
{
  if (index >= vec->size)
  {
    fprintf(stderr, "Index out of bounds\n");
    exit(1);
  }
  int value = vec->data[index];
  for (size_t i = index; i < vec->size - 1; i++)
  {
    vec->data[i] = vec->data[i + 1];
  }
  vec->size--;

  if (vec->size < vec->capacity / 4)
  {
    resizeVector(vec, vec->capacity / 2);
  }
  return value;
}

void freeVector(Vector_i *vec)
{
  free(vec->data);
  vec->data = NULL;
  vec->size = 0;
  vec->capacity = 0;
}