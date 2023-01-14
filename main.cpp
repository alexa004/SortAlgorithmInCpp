#ifndef DEBUG
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#endif

#include <iostream>
#include <catch2/catch_all.hpp>

#include "utils/sort.h"
#include "utils/rank.h"
#include "utils/other.h"

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return Catch::Session().run(argc, argv);
}
