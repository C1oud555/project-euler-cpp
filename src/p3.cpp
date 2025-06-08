#include "common.hpp"

// NOTE: Largest Prime Factor

inline size_t p3(size_t limit) {
  auto ret = 0;
  for (int i = 3; i < limit; i++) {
    if (limit % i == 0) {
      size_t op = limit / i;
      if (is_prime(op)) {
        ret = op;
        break;
      }
    }
  }

  return ret;
}

TEST_CASE("project euler p3") {
  constexpr size_t gold = 6857;
  constexpr size_t limit = 600851475143;

  auto actual = p3(limit);

  REQUIRE(gold == actual);
}
