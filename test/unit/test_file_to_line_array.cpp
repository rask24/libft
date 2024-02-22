#include "gtest/gtest.h"

extern "C" {
#include "libft.h"
}

TEST(file_to_line_array, normal) {
  const char *file_path = "./test/unit/fixture/normal.txt";
  char **lines = file_to_line_array(const_cast<char *>(file_path));
  std::vector<char const *> ans = {"abc\n", "def\n", "123\n"};

  for (int i = 0; i < (int)ans.size(); ++i) {
    EXPECT_EQ(strcmp(ans[i], lines[i]), 0);
  }
}

TEST(file_to_line_array, empty) {
  const char *file_path = "./test/unit/fixture/empty.txt";
  char **lines = file_to_line_array(const_cast<char *>(file_path));

  EXPECT_EQ(lines[0], nullptr);
}

TEST(file_to_line_array, noNewline) {
  const char *file_path = "./test/unit/fixture/one_line_with_no_newline.txt";
  char **lines = file_to_line_array(const_cast<char *>(file_path));

  EXPECT_EQ(
      strcmp(lines[0], "abslkadjflsdjf;lsjdl;fkjsadl;fjsldjflsdjflsjdfksjldfj"),
      0);
}

TEST(file_to_line_array, lineNoTrailingNewline) {
  const char *file_path = "./test/unit/fixture/lines_no_trailing_newline.txt";
  char **lines = file_to_line_array(const_cast<char *>(file_path));
  std::vector<char const *> ans = {"hello\n", "world\n", "42\n", "tokyo"};

  for (int i = 0; i < (int)ans.size(); ++i) {
    EXPECT_EQ(strcmp(ans[i], lines[i]), 0);
  }
}
