#include <stdio.h>

int main(void) 
{
  int x = 0x01234567;
  
  printf("%p\n", (int*) NULL);

  printf("%x\n", x);
  return 0;
}
