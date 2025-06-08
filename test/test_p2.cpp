#include "p2.hpp"

int main(int argc, char *argv[]) {
  constexpr size_t gold = 4613732;
  auto actual = p2(4e6);

  if (!compare_result(gold, actual)) {
    fmt::println("gold   : {}", gold);
    fmt::println("actual : {}", actual);
  } else {
    fmt::println("Pass");
  }
  return 0;
}
