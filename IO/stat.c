#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[], char *envp[]) {
  printf("Hello World!\n");

  struct stat st;
  
  printf("Return value of stat : %d\n", stat(argv[1], &st));

  printf("device : %lu\n"
         "mode   : %u\n"
         "nlink  : %lu\n"
         "userid : %u\n"
         "grpid  : %u\n"
         "size   : %lu\n"
         "blksize: %lu\n"
         "blnks  : %lu\n", st.st_dev, st.st_mode, st.st_nlink, st.st_uid, st.st_gid, st.st_size, st.st_blksize, st.st_blocks);

  return 0;
}
