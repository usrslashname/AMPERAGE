#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage:\n");
    printf("cat [-u] [FILE]\n");
    return 1;
  }

  if (argc != 1) {
    int file_idx = 1;

    if (argv[1][0] == '-' && argv[1][1] == 'u' && argv[1][2] == '\0') {
      file_idx = 2;
    }

    int fd = open(argv[file_idx], O_RDONLY);

    posix_fadvise(fd, 0, file_size, POSIX_FADV_SEQUENTIAL);
    posix_fadvise(fd, 0, file_size, POSIX_FADV_WILLNEED);
