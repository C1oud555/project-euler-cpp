#include "common.h"
#include <cstddef>
#include <string>

// NOTE: Largest Product in a Series

bool is_pythagorean(size_t a, size_t b, size_t c) {
  return (a * a) + (b * b) == (c * c);
}

inline size_t p9(size_t sum = 0) {
  size_t bound = sum / 3 + 1;
  for (size_t a = 1; a < sum - 2; a++) {
    for (size_t b = 1; b < sum - 2; b++) {
      auto c = sum - a - b;
      if (is_pythagorean(a, b, c)) {
        return a * b * c;
      }
    }
  }
  return -1;
}

TEST_CASE("project euler p9") {
  constexpr size_t gold = 31875000;
  constexpr size_t limit = 1000;

  auto actual = p9(limit);

  REQUIRE(gold == actual);
}
