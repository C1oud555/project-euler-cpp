#include "p1.hpp"

bool compare_result(auto gold, auto actual) {

  fmt::println("gold : {}", gold);
  fmt::println("yours: {}", actual);

  return gold == actual;
}

int main(int argc, char *argv[]) {
  constexpr size_t gold = 233168;
  auto actual = p1(1000);

  if (!compare_result(gold, actual)) {
    fmt::println("Not right!");
    return -1;
  }
  return 0;
}
