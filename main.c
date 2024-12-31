#include <stdio.h>

#include "src/utils/vector.h"

int main()
{
  Vector_i v;
  initVector(&v, 0);

  for (int i = 0; i < 40; i++)
  {
    pushBack(&v, i);
  }

  for (int i = 0; i < v.size; i++)
  {
    printf("Element at index %d: %d\n", i, getElementAt(&v, i));
  }

  for (int i = 0; i < 30; i++)
  {
    deleteAt(&v, 2);
  }
  printf("After delete:\n");
  for (int i = 0; i < v.size; i++)
  {
    printf("Element at index %d: %d\n", i, getElementAt(&v, i));
  }
  printf("Size: %ld\n", v.size);
  printf("Capacity: %ld\n", v.capacity);
  freeVector(&v);

  return 0;
}