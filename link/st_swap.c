extern int array[];
int *ap0 = &array[0];
static int *ap1;
int k = 0;

static int incr() {
  static int c = 1;
  return c++;
}

void swap() {
  int temp;

  k = incr();
  ap1 = &array[1];
  temp = *ap0;
  *ap0 = *ap1;
  *ap1 = temp;
}
