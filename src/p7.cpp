#include "common.hpp"

// NOTE: 10 001st Prime

inline size_t p7(size_t limit) {
  size_t ret = 2;
  size_t cnt = 0;
  while (cnt < limit) {
    if (is_prime(ret)) {
      cnt += 1;
    }
    ret += 1;
  }

  return ret - 1;
}

TEST_CASE("project euler p7") {
  constexpr size_t gold = 104743;
  constexpr size_t limit = 10001;

  auto actual = p7(limit);

  REQUIRE(gold == actual);
}
