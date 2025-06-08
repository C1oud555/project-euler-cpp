#include "common.hpp"

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

  return ranges::fold_left_first(even_fib_seq, std::plus<size_t>{}).value();
}

TEST_CASE("project euler", "[p2]") {
  constexpr size_t gold = 46137320;
  auto actual = p2(4e6);
  REQUIRE(gold == actual);
}
