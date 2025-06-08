#include "common.hpp"

// NOTE: Smallest Multiple

bool evenly_divisble(size_t n, size_t hbound) {
  for (int i = 1; i < hbound; i++) {
    if (n % i != 0) {
      return false;
    }
  }
  return true;
}

inline size_t p5(size_t limit) {
  int i = 1;
  while (!evenly_divisble(i, limit)) {
    i++;
  }
  return i;
}

TEST_CASE("project euler p5") {
  constexpr size_t gold = 232792560;
  constexpr size_t limit = 20;

  auto actual = p5(limit);

  REQUIRE(gold == actual);
}
