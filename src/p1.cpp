#include "common.hpp"

/*
 * Find the sum of all the multiples of 3 ro 5 below limits
 */
inline size_t p1(size_t limit) {
  auto seqs = views::iota(0) | views::take(limit) |
              views::filter([](size_t i) { return i % 3 == 0 || i % 5 == 0; });

  return ranges::fold_left_first(seqs, std::plus<size_t>{}).value();
}

TEST_CASE("project euler", "[p1]") {
  constexpr size_t gold = 233168;
  auto actual = p1(1000);
  REQUIRE(gold == actual);
}
