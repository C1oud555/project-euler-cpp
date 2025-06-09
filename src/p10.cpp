#include "common.h"
#include <cstddef>

// NOTE: Largest Product in a Series

inline size_t p10(size_t limit) {
  size_t sum = 0;
  for (size_t i = 2; i < limit; i++) {
    if (is_prime(i)) {
      sum += i;
    }
  }
  return sum;
}

TEST_CASE("project euler p10") {
  constexpr size_t gold = 142913828922;
  constexpr size_t limit = 2e6;

  auto actual = p10(limit);

  REQUIRE(gold == actual);
}
