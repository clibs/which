
# which

  Lookup executable via __PATH__ environment variable or a given path string.

## Installation

  Install with [clib](https://github.com/clibs/clib):

```
$ clib install clibs/which
```

## API

```c
char *
which(char *name);

char *
which_path(char *name, char *path);
```

# License

  MIT
  