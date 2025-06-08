#include "common.hpp"

// NOTE: Sum Square Difference

inline size_t p6(size_t limit) {
  auto seq = views::iota(1) | views::take(limit);

  auto sum_seq = ranges::fold_left(seq, 0, std::plus<size_t>{});
  auto square_of_sum = sum_seq * sum_seq;

  auto seq_square = seq | views::transform([](size_t n) { return n * n; });
  auto sum_of_square = ranges::fold_left(seq_square, 0, std::plus<size_t>{});

  return square_of_sum - sum_of_square;
}

TEST_CASE("project euler p6") {
  constexpr size_t gold = 25164150;
  constexpr size_t limit = 100;

  auto actual = p6(limit);

  REQUIRE(gold == actual);
}
