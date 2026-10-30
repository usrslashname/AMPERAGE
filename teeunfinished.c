#define _XOPEN_SOURCE = 600
#define BUFFER_SIZE = 16384
#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void parse_arguments(int argc, char *argv[], int index) {
    if (index >= argc) {
        return;
    }

    /* Parse the current argument */
    if (strcmp(argv[index], "-a") == 0) {
        config->append = true;
    } else if (strcmp(argv[index], "-i") == 0) {
        config->ignore_interrupts = true;
    } else {
        printf("Usage:\n");
        printf("tee [-ai] [FILE]\n");
    }

    /* Process the next argument */
    parse_arguments(argc, argv, index + 1);
}

void pipeline_t(int argc, char *argv[]) {
  int *fds = (int *)calloc(16384, sizeof(int));
  if (fds != NULL) {
    fds[0] = 1;
  }
  
  int is_flag = (argc > 1 && argv[1][0] == '-' && argv[1][1] != '\0');
  int count_flags = is_flag ? (argv[1][1 + strspn(argv[1] + 1, "ai")] == '\0' ? 1 : 0) : 0;
  
  int count = argc - count_flags;
  
}

int clear_pipeline() {
  /* Quick and dirty safety check */
  if (p == NULL) {
    printf("Error: Incoming pointer is null");
    return 1;
  }

  
}

int main() {
  
