#include "common.h"

bool is_prime(size_t n) {
  if (n == 2 || n == 3 || n == 5 || n == 7) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n < 2) {
    return false;
  }
  size_t bound = static_cast<size_t>(std::sqrt(n)) + 1;
  for (int i = 3; i <= bound; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

TEST_CASE("project euler common", "[is_prime]") {
  REQUIRE(!is_prime(0));
  REQUIRE(!is_prime(1));
  REQUIRE(is_prime(2));
  REQUIRE(is_prime(3));
  REQUIRE(!is_prime(4));
  REQUIRE(is_prime(5));
  REQUIRE(!is_prime(6));
  REQUIRE(is_prime(7));
  REQUIRE(!is_prime(8));
  REQUIRE(!is_prime(9));
}
