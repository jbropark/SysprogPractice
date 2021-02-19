static int static_int;

static int static_func(void)
{
  return 1;
}

int global_int;

int global_init_int = 1;

int global_uninit_int = 0;

extern int extern_int;

extern int extern_func(void);

int func_declare();

int func_definition()
{
  return 4;
}

int main(int argc, char *argv[])
{
  int a;
  a = global_int + static_int + extern_int + func_declare() + func_definition() + extern_func() + static_func() 
      + global_init_int + global_uninit_int;
}
