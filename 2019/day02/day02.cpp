﻿#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <random>

using namespace std;

std::default_random_engine engine;

std::array<int, 3> day2(std::vector<int> input) {
    if (4 > input.size()) {
        return {-1, -1, -1};
    }

    std::uniform_int_distribution<int> dist(0, 100);
    input[1] = dist(engine);
    input[2] = dist(engine);

    for (int i = 0; i < input.size(); i += 4) {
        std::function<int(int, int)> op;
        if (1 == input[i]) {
            op = std::plus<int>();
        } else if (2 == input[i]) {
            op = std::multiplies<int>();
        } else if (99 == input[i]) {
            break;
        } else {
            std::cerr << "error" << std::endl;
            return {-1, -1, -1};
        }
        input[input[i + 3]] = op(input[input[i + 1]], input[input[i + 2]]);
    }
    return {input[0], input[1], input[2]};
}

int main() {
    int result = 0;
    std::vector<int> rv;
    while (19690720 != result) {
        auto r = day2(
                {1, 0, 0, 3, 1, 1, 2, 3, 1, 3, 4, 3, 1, 5, 0, 3, 2, 1, 10, 19, 1, 6, 19, 23, 1, 10, 23, 27, 2, 27, 13,
                 31, 1, 31, 6, 35, 2, 6, 35, 39, 1, 39, 5, 43, 1, 6, 43, 47, 2, 6, 47, 51, 1, 51, 5, 55, 2, 55, 9, 59,
                 1, 6, 59, 63, 1, 9, 63, 67, 1, 67, 10, 71, 2, 9, 71, 75, 1, 6, 75, 79, 1, 5, 79, 83, 2, 83, 10, 87, 1,
                 87, 5, 91, 1, 91, 9, 95, 1, 6, 95, 99, 2, 99, 10, 103, 1, 103, 5, 107, 2, 107, 6, 111, 1, 111, 5, 115,
                 1, 9, 115, 119, 2, 119, 10, 123, 1, 6, 123, 127, 2, 13, 127, 131, 1, 131, 6, 135, 1, 135, 10, 139, 1,
                 13, 139, 143, 1, 143, 13, 147, 1, 5, 147, 151, 1, 151, 2, 155, 1, 155, 5, 0, 99, 2, 0, 14, 0});
        result = r[0];
        if (19690720 == r[0]) {
            rv = std::vector<int>(std::begin(r), std::end(r));
        }
    }

    std::cout << rv[1] << " " << rv[2] << std::endl;

    return 0;
}
