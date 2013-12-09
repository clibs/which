
#include "src/which.h"
#include "deps/describe.h"

int
main() {
  describe("which", {
    char mock_path[] = "/foo/bar:/baz/qax:/usr/local/bin/wer:./test:.";

    it("should return NULL when no matching binary is found", {
      assert(NULL == which("foobar"));
    });
    it("should return the path of the name", {
      assert_str_equal("./test", which_path("test", mock_path));
    });
    it("should return NULL if the given name isn't executable", {
      assert(NULL == which_path("test.c", mock_path));
    });
  });
}
