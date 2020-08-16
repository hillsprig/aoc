#include <set>
#include <tuple>
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

#include <boost/algorithm/string.hpp>

enum class Direction : char {
    Up = 'U',
    Down = 'D',
    Right = 'R',
    Left = 'L',
};

namespace {
    using Input = std::array<std::string, 2>;
    using Movement = std::tuple<Direction, int>;
    using Point = std::tuple<int, int>;
    using Plot = std::vector<Point>;
}

Movement stringToMovement(const std::string& str) {
    Direction direction = static_cast<Direction>(str[0]);
    int distance = std::stoi(str.substr(1));

    return std::make_tuple(direction, distance);
}

void walk(Plot &plot, const Movement &mov) {
    Point p = *plot.end();
    switch (std::get<0>(mov)) {
        case Direction::Up:
            for (auto i = std::get<0>(p); i <= std::get<1>(mov); ++i) {
                plot.push_back(std::make_tuple(i, std::get<1>(p)));
            }
            break;
        case Direction::Down:
            for (auto i = std::get<0>(p); i >= std::get<1>(mov); --i) {
                plot.push_back(std::make_tuple(i, std::get<1>(p)));
            }
            break;
        case Direction::Right:
            for (auto i = std::get<1>(p); i <= std::get<1>(mov); ++i) {
                plot.push_back(std::make_tuple(std::get<0>(p), i));
            }
            break;
        case Direction::Left:
            for (auto i = std::get<1>(p); i >= std::get<1>(mov); --i) {
                plot.push_back(std::make_tuple(std::get<0>(p), i));
            }
            break;
    }
}

int distanceToCentralPort(const Input& input) {
    Plot plot[2];
    for (auto &p : plot) {
        p.push_back(std::make_tuple(0, 0));
    }
    for (std::size_t i = 0; i < input.size(); ++i) {
        std::vector<std::string> values;

        boost::split(values, input[i], [](char c){ return c == ','; });

        for (auto& v : values) {
            walk(plot[i], stringToMovement(v));
        }
    }

    for (auto &p : plot) {
        std::sort(p.begin(), p.end());
        std::erase(std::unique(p.begin(), p.end(), p.end()));
    }

    return 0;
}

int main() {
    std::array<Input, 2> input = {{
                                          {
                                                  "R75,D30,R83,U83,L12,D49,R71,U7,L72",
                                                  "U62,R66,U55,R34,D71,R55,D58,R83"
                                          },
                                          {
                                                  "R75,D30,R83,U83,L12,D49,R71,U7,L72",
                                                  "U62,R66,U55,R34,D71,R55,D58,R83"
                                          },
                                  }};
    for (const auto& i : input) {
        distanceToCentralPort(i);
    }
}