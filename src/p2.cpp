#include "common.h"

// NOTE: Even Fibonacci Numbers

inline size_t p2(size_t limit) {
  size_t i = 0, j = 1;
  auto fib_seq = views::generate([&]() -> int {
    size_t tmp = i;
    i += j;
    std::swap(i, j);
    return tmp;
  });

  auto even_fib_seq = fib_seq |
                      views::take_while([=](size_t n) { return n < limit; }) |
                      views::filter([](size_t n) { return n % 2 == 0; });

  return ranges::fold_left(even_fib_seq, 0, std::plus<size_t>{});
}

TEST_CASE("project euler p2") {
  constexpr size_t gold = 4613732;
  constexpr size_t limit = 4e6;

  auto actual = p2(limit);

  REQUIRE(gold == actual);
}
