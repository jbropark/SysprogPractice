#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


static void *(*malloc_orig)(size_t);
static void (*free_orig)(void *);
static void *(*calloc_orig)(size_t, size_t);
static void *(*realloc_orig)(void *, size_t);


__attribute__((constructor))
void __init_memory_inspect(void)
{
  char *error;

  dlerror();

  fputs("init\n", stderr);

  malloc_orig = dlsym(RTLD_NEXT, "malloc");
  if ((error = dlerror()) != NULL) { 
    fprintf(stderr, "malloc: %s\n", error);
    exit(EXIT_FAILURE);
  }

  free_orig = dlsym(RTLD_NEXT, "free");
  if ((error = dlerror()) != NULL) {
    fprintf(stderr, "free: %s\n", error);
    exit(EXIT_FAILURE);
  }

  calloc_orig = dlsym(RTLD_NEXT, "calloc");
  if ((error = dlerror()) != NULL) {
    fprintf(stderr, "calloc: %s\n", error);
    exit(EXIT_FAILURE);
  }

  realloc_orig = dlsym(RTLD_NEXT, "realloc");
  if ((error = dlerror()) != NULL) {
    fprintf(stderr, "realloc: %s\n", error);
    exit(EXIT_FAILURE);
  }
}

void *malloc(size_t size)
{
  char buf[128];
  static unsigned long cnt = 0;
  void *ret;

  ret = malloc_orig(size);
  
  snprintf(buf, 128, "malloc[%lu] : %p (%lu)\n", size, ret, ++cnt);
  fputs(buf, stderr);
  fflush(stderr);

  return ret;
}

void free(void *ptr)
{
  char buf[128];
  static unsigned long cnt = 0;
  
  free_orig(ptr);

  snprintf(buf, 128, "free : %p (%lu)\n", ptr, ++cnt);
  fputs(buf, stderr);
  fflush(stderr);
}

void *calloc(size_t nmemb, size_t size)
{
  char buf[128];
  static unsigned long cnt = 0;
  void *ret;

  ret = calloc_orig(nmemb, size);
  
  snprintf(buf, 128, "calloc[%lu] : %p (%lu)\n", size, ret, ++cnt);
  fputs(buf, stderr);
  fflush(stderr);

  return ret;
}

void *realloc(void *ptr, size_t size)
{
  char buf[128];
  static unsigned long cnt = 0;
  void *ret;

  ret = realloc_orig(ptr, size);
  
  snprintf(buf, 128, "realloc[%lu] : %p (%lu)\n", size, ret, ++cnt);
  fputs(buf, stderr);
  fflush(stderr);

  return ret;
}



