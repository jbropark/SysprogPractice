#include <stdio.h>
#include "header.h"

int global = 5;


int main(int argc, char *argv[]) 
{
  static int global = 55;
  printf("%d\n", global);
}
