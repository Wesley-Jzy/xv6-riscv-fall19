#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int xticks;

  if (argc != 2) {
    printf("sleep: need one integer argument\n");
    exit();
  }

  xticks = atoi(argv[1]);
  sleep(xticks);

  exit();
}
