#include "common.h"
#include <cstddef>

// NOTE: Longest Collatz Sequence

size_t collatz_seq_cnt(size_t n) {
  size_t seq_cnt = 1;
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = 3 * n + 1;
    }
    seq_cnt += 1;
  }
  return seq_cnt;
}

inline size_t p14(size_t limit) {
  size_t max = 1;
  size_t num = 1;
  for (size_t i = 1; i < limit; i++) {
    size_t seq_cnt = collatz_seq_cnt(i);
    if (seq_cnt > max) {
      max = seq_cnt;
      num = i;
    }
  }
  return num;
}

TEST_CASE("project euler p14") {
  constexpr size_t gold = 837799;
  constexpr size_t limit = 1e6;

  auto actual = p14(limit);

  REQUIRE(gold == actual);
}

TEST_CASE("project euler p14", "[collatz_seq_cnt]") {
  REQUIRE(collatz_seq_cnt(13) == 10);
}
