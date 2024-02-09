#include <gtest/gtest.h>

#include <string>

extern "C" {
#include <string.h>

#include "libft.h"
}

#define CHECK_EQ(func, ...) EXPECT_EQ(ft_##func(__VA_ARGS__), func(__VA_ARGS__))

TEST(strlen_test, libft_test) {
  std::string s0("");
  std::string s1("H");
  std::string s2("He");
  std::string s3("Hel");
  std::string s4("Hell");
  std::string s5("Hello");

  CHECK_EQ(strlen, s0.c_str());
  CHECK_EQ(strlen, s1.c_str());
  CHECK_EQ(strlen, s2.c_str());
  CHECK_EQ(strlen, s3.c_str());
  CHECK_EQ(strlen, s4.c_str());
  CHECK_EQ(strlen, s5.c_str());
}

TEST(strncmp_test, libft_test) {
  std::string s1("Hello World");
  std::string s2("Hello:World");
  size_t len = s1.size();

  for (size_t i = 0; i < len + 2; ++i) {
    CHECK_EQ(strncmp, s1.c_str(), s2.c_str(), i);
  }
}

TEST(strcmp_test, libft_test) {
  std::string s1("Hello World");
  std::string s2("Hello:World");

  CHECK_EQ(strcmp, s1.c_str(), s1.c_str());
  CHECK_EQ(strcmp, s2.c_str(), s2.c_str());
  CHECK_EQ(strcmp, s1.c_str(), s2.c_str());
  CHECK_EQ(strcmp, s2.c_str(), s1.c_str());
}

TEST(strstr_test, libft_test) {
  std::string s1("abcdefg");
  std::string s2("def");
  std::string s3("dek");
  std::string s4("");

  CHECK_EQ(strstr, s1.c_str(), s2.c_str());
  CHECK_EQ(strstr, s1.c_str(), s3.c_str());
  CHECK_EQ(strstr, s1.c_str(), s4.c_str());
  CHECK_EQ(strstr, s1.c_str(), s1.c_str());
  CHECK_EQ(strstr, s4.c_str(), s4.c_str());
  CHECK_EQ(strstr, s2.c_str(), s1.c_str());
}

static void *convert_const_char_to_void(const char *str) {
  const void *const_element = static_cast<const void *>(str);
  void *element = const_cast<void *>(const_element);

  return element;
}

TEST(ft_lst_before, test) {
  t_list *stack;
  void *element0 = convert_const_char_to_void("0");
  void *element1 = convert_const_char_to_void("1");
  void *element2 = convert_const_char_to_void("2");
  void *element3 = convert_const_char_to_void("3");
  void *element4 = convert_const_char_to_void("4");
  t_list *lst0 = ft_lstnew(element0);
  t_list *lst1 = ft_lstnew(element1);
  t_list *lst2 = ft_lstnew(element2);
  t_list *lst3 = ft_lstnew(element3);
  t_list *lst4 = ft_lstnew(element4);
  t_list *dummy = ft_lstnew(convert_const_char_to_void("dummy"));

  stack = NULL;
  ft_lstadd_back(&stack, lst0);
  ft_lstadd_back(&stack, lst1);
  ft_lstadd_back(&stack, lst2);
  ft_lstadd_back(&stack, lst3);
  ft_lstadd_back(&stack, lst4);

  // not found
  EXPECT_EQ(ft_lst_before(stack, lst0), nullptr);
  EXPECT_EQ(ft_lst_before(stack, dummy), nullptr);

  // found
  EXPECT_EQ(ft_lst_before(stack, lst1)->content, element0);
  EXPECT_EQ(ft_lst_before(stack, lst2)->content, element1);
  EXPECT_EQ(ft_lst_before(stack, lst3)->content, element2);
  EXPECT_EQ(ft_lst_before(stack, lst4)->content, element3);
}

TEST(ft_abs, test) {
  EXPECT_EQ(ft_abs(42), 42);
  EXPECT_EQ(ft_abs(0), 0);
  EXPECT_EQ(ft_abs(-42), 42);
}
