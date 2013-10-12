
//
// which.c
//
// Copyright (c) 2013 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "which.h"

#ifdef _WIN32
#define DELIMITER   ";"
#else
#define DELIMITER   ":"
#endif

/*
 * Lookup executable `name` within the PATH environment variable.
 */

char *
which(char *name) {
  return which_path(name, getenv("PATH"));
}

/*
 * Lookup executable `name` within `path`.
 */

char *
which_path(char *name, char *path) {
  char *tok = strtok(path, DELIMITER);

  while (tok) {
    // path
    int len = strlen(tok) + 1 + strlen(name);
    char *file = malloc(len);
    if (!file) return NULL;
    sprintf(file, "%s/%s", tok, name);

    // executable
    if (0 == access(file, X_OK)) {
      return file;
    }

    // next token
    tok = strtok(NULL, DELIMITER);
    free(file);
  }

  return NULL;
}
