// Copyright 2018 Glyn Matthews.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt of copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <gtest/gtest.h>
#include <string>
#include <skyr/domain.hpp>

using param = std::pair<std::string, std::string>;

class domain_tests : public ::testing::TestWithParam<param> {};

INSTANTIATE_TEST_CASE_P(
    domain_to_ascii_tests,
    domain_tests,
    ::testing::Values(
        param{"example.com", "example.com"},
        param{"你好你好", "xn--6qqa088eba"}
    ));

TEST_P(domain_tests, domain_to_ascii_tests) {
  auto input = std::string();
  auto expected = std::string();
  std::tie(input, expected) = GetParam();

  auto instance = skyr::domain_to_ascii(input);
  ASSERT_TRUE(instance);
  EXPECT_EQ(expected, instance.value());
}
