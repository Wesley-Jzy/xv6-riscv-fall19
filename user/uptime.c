#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int xticks;

  if (argc > 1) {
    printf("uptime: need no arguements\n");
    exit();
  }

  xticks = uptime();
  printf("ticks: %d\n", xticks);
  exit();
}
