#include "common.hpp"

// NOTE: Largest Palindrome Product

bool is_palindrome(size_t n) {
  auto n_s = std::to_string(n);
  auto n_sr = std::to_string(n);
  std::reverse(n_sr.begin(), n_sr.end());
  return n_s == n_sr;
}

inline size_t p4(size_t limit) {
  size_t hbound = 1;
  // limit = 3
  for (int i = 0; i < limit; i++) {
    hbound *= 10;
  }
  auto lbound = (hbound / 10);
  hbound -= 1;
  size_t ret = 0;

  std::vector<size_t> all_palindromes{};
  for (size_t x = hbound; x >= lbound; x--) {
    auto check = x * x;
    if (is_palindrome(check)) {
      all_palindromes.push_back(check);
    }
    for (size_t y = x - 1; y >= lbound; y--) {
      auto check = x * y;
      if (is_palindrome(check)) {
        all_palindromes.push_back(check);
      }
    }
  }

  return ranges::max(all_palindromes);
}

TEST_CASE("project euler p4", "[is_palindrome]") {
  REQUIRE(is_palindrome(202));
  REQUIRE(!is_palindrome(102));
  REQUIRE(!is_palindrome(204));
  REQUIRE(is_palindrome(101));
  REQUIRE(is_palindrome(303));
  REQUIRE(is_palindrome(30303));
  REQUIRE(is_palindrome(22));
  REQUIRE(is_palindrome(6));
}

TEST_CASE("project euler p4") {
  constexpr size_t gold = 906609;
  constexpr size_t limit = 3;

  auto actual = p4(limit);

  REQUIRE(gold == actual);
}
