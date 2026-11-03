#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage:\n");
    printf("tty\n");
    return 1;
  }

  if (argc == 1) {
    if (!isatty(STDIN_FILENO)) {
      printf("Not a TTY.\n");
      return 0;
    } else {
      char *tty_name = ttyname(STDIN_FILENO);
      printf("%s\n", tty_name);
      return 0;
    }
  }
}
