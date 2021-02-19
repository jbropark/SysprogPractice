#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int b = 4;
  int arr[13];
  int *a;
  int arr2[20];
  a = malloc(sizeof(int));
  *a = 5;
  printf("number : %d\n", *a);
  printf("b   : %p\n"
         "arr : %p\n"
         "arr2: %p\n"
         "a   : %p\n", &b, arr, arr2, &a); 
  free(a);
}
