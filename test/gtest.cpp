#include <string>
#include <gtest/gtest.h>

extern "C" {
	#include <string.h>
	#include "libft.h"
}

#define CHECK_EQ(func, ...) \
	EXPECT_EQ(ft_ ## func(__VA_ARGS__), func(__VA_ARGS__))

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
