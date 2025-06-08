#pragma once

#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <cstdint>

#include <range/v3/all.hpp>

#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

namespace views = ranges::views;

bool compare_result(auto gold, auto actual) { return gold == actual; }

bool is_prime(size_t n);
