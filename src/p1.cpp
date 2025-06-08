#include "common.h"

// NOTE: Multiples of 3 or 5

inline size_t p1(size_t limit) {
  auto seqs = views::iota(0) | views::take(limit) |
              views::filter([](size_t i) { return i % 3 == 0 || i % 5 == 0; });

  return ranges::fold_left(seqs, 0, std::plus<size_t>{});
}

TEST_CASE("project euler p1") {
  constexpr size_t gold = 233168;
  constexpr size_t limit = 1000;

  auto actual = p1(limit);

  REQUIRE(gold == actual);
}
