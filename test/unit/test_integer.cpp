// Copyright 2024, reasuke.

#include "gtest/gtest.h"
#include "unit_test_utils.hpp"

extern "C" {
#include "libft.h"
}

TEST(ft_abs, test) {
  EXPECT_EQ(ft_abs(42), 42);
  EXPECT_EQ(ft_abs(0), 0);
  EXPECT_EQ(ft_abs(-42), 42);
}

TEST(ft_chmax, chooseMax) {
  int a = 0;
  int b = 42;

  EXPECT_TRUE(ft_chmax(&a, b));
  EXPECT_EQ(a, 42);
}

TEST(ft_chmax, notChooseMax) {
  int a = 42;
  int b = 0;

  EXPECT_FALSE(ft_chmax(&a, b));
  EXPECT_EQ(a, 42);
}

TEST(ft_chmin, chooseMin) {
  int a = 42;
  int b = 0;

  EXPECT_TRUE(ft_chmin(&a, b));
  EXPECT_EQ(a, b);
}

TEST(ft_chmin, notChooseMin) {
  int a = 0;
  int b = 42;

  EXPECT_FALSE(ft_chmin(&a, b));
  EXPECT_EQ(a, 0);
}

TEST(ft_max, test) {
  EXPECT_EQ(ft_max(0, 0), 0);
  EXPECT_EQ(ft_max(42, 0), 42);
  EXPECT_EQ(ft_max(0, 42), 42);
}

TEST(ft_min, test) {
  EXPECT_EQ(ft_min(0, 0), 0);
  EXPECT_EQ(ft_min(42, 0), 0);
  EXPECT_EQ(ft_min(0, 42), 0);
}

TEST(ft_swap, test) {
  int a = 42;
  int b = 0;

  ft_swap(&a, &b);
  EXPECT_EQ(a, 0);
  EXPECT_EQ(b, 42);
}
