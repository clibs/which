
#include "src/which.h"
#include "describe/describe.h"

describe("which", {
  char mock_path[] = "/foo/bar:/baz/qax:/usr/local/bin/wer:./test:.";

  it("should return NULL when no matching binary is found", {
    assert(NULL == which("foobar"));
  });

  it("should return the path of the name", {
    char *bin = which_path("test", mock_path);
    assert_str_equal("./test", bin);
    free(bin);
  });

  it("should return NULL if the given name isn't executable", {
    assert(NULL == which_path("test.c", mock_path));
  });
});
