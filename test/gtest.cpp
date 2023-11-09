#include <string>
#include <gtest/gtest.h>

extern "C" {
	#include <string.h>
	#include "libft.h"
}

#define STRLEN_CHECK_EQ(...) { \
	EXPECT_EQ(ft_strlen(__VA_ARGS__), strlen(__VA_ARGS__)); }

TEST(strlen_test, libft_test) {
	std::string s0("");
	std::string s1("H");
	std::string s2("He");
	std::string s3("Hel");
	std::string s4("Hell");
	std::string s5("Hello");

	STRLEN_CHECK_EQ(s0.c_str());
	STRLEN_CHECK_EQ(s1.c_str());
	STRLEN_CHECK_EQ(s2.c_str());
	STRLEN_CHECK_EQ(s3.c_str());
	STRLEN_CHECK_EQ(s4.c_str());
	STRLEN_CHECK_EQ(s5.c_str());
}

#define STRNCMP_CHECK_EQ(...) { \
	EXPECT_EQ(ft_strncmp(__VA_ARGS__), strncmp(__VA_ARGS__)); }

TEST(strncmp_test, libft_test) {
	std::string s1("Hello World");
	std::string s2("Hello:World");
	size_t len = s1.size();

	for (size_t i = 0; i < len + 2; ++i) {
		STRNCMP_CHECK_EQ(s1.c_str(), s2.c_str(), i);
	}
}
