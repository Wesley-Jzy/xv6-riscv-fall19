#include <kernel/types.h>
#include <user/user.h>

const char *PING = "P"; // Parent
const char *PONG = "C"; // Child

int main(int argc, char *argv[])
{
  int parent_fd[2], child_fd[2];
  char buf[1];
  
  pipe(parent_fd);
  pipe(child_fd);

  /**
   * parent: write to parent_fd[1], read from child_fd[0]
   * child: read from parent_fd[0], write to child_fd[1]
   */
  if (fork() == 0) {
    close(parent_fd[1]);
    close(child_fd[0]);
    read(parent_fd[0], buf, 1);
    printf("%d: received ping\n", getpid());
    write(child_fd[1], PONG, 1);
    close(parent_fd[0]);
    close(child_fd[1]);
    exit();
  } else {
    close(parent_fd[0]);
    close(child_fd[1]);
    write(parent_fd[1], PING, 1);
    read(child_fd[0], buf, 1);
    printf("%d: received pong\n", getpid());
    close(parent_fd[1]);
    close(child_fd[0]);
    wait();
  }

  exit();
}
