
#include <stdio.h>
#include <stdlib.h>
#include "src/which.h"

int
main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "<name> required\n");
    exit(1);
  }

  char *name = argv[1];
  char *path = which(name);

  printf("%s: %s\n", name, path ? path : "not found");

  return 0;
}