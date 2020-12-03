#include <array>

namespace input {

constexpr std::array sample = {
    "..##.......", "#...#...#..", ".#....#..#.", "..#.#...#.#",
    ".#...##..#.", "..#.##.....", ".#.#.#....#", ".#........#",
    "#.##...#...", "#...##....#", ".#..#...#.#",
};

constexpr std::array puzzle = {
    ".#......#..####.....#..#.......", "#.#...#...#..#.#...#.#...##.##.",
    "#.#....#..........#...##.....##", "#.#.#.....##......#.#.......###",
    "..#..###....#.#....#.#.#..#....", ".......#.#....##..##...#...#...",
    "..#..#..#..###.......#.....#.#.", ".#.......#...##...##.##......##",
    "#.#.##..##.#..#....#..###..#.#.", "#.....#.#.........#.....##.#.#.",
    "..#.#....##..#...#...##........", "......#....#..##.#.#......###..",
    ".......#.......#......##...#...", ".##.....#.......#...###.....##.",
    ".#...#.##..##.#..##....#.......", "..#......##...#..#...#.#.##.###",
    ".##.##.....##....#..#......#.#.", ".#.....#..###..#.##.#.....##.#.",
    "......##..........#..........#.", ".##....#.....#..##.#..#.#..###.",
    "..##.......#....#...##...#..#..", ".##...#.....#.###.#.#..#...#.#.",
    ".....##.#.##..##...#...........", "..#..###.##.#.#.###...###..#.#.",
    ".#........#..#.#........#.#...#", "....##.......#....#.#.##.#.....",
    "....##........######..###..#.#.", "#.#.#............#.......#..#..",
    "...##...#.##.....#.#..#......#.", "......#.##.#....##..#.#..###...",
    "##.....#.#....#....#.##.#.###..", "#..#..#..##.#..##.##.##.#.##...",
    ".###.####..#..#........#.....##", ".......##..#.......#...........",
    ".##...#............#.#.##...#..", "....##.....#...##..#..#.#..###.",
    "...#.....#####.#..#...##....##.", "#.....#.#.#....##.......##.#.#.",
    "......#.#..#.##.#######......#.", "#.##...##....#..###.#.......#..",
    ".....##...#....#...#....##.##.#", "....###......#...###..#......##",
    "..#...##..##.######..#.#......#", "......##....#....##..#......##.",
    ".#...#..##..#.###.#......#....#", "##....##..#..####.#.....#...#..",
    ".#.......#...#.......##......#.", "......#...#...#........#.......",
    ".#........#.###...#..####.#..#.", "##...#.#............#.....###..",
    ".....###.#.##...........###..#.", ".#.#...#.....#.#.##..##...####.",
    "..##.......#..#.##.#....#.....#", ".#..#.#..####.....###.#.....#..",
    "..#..###.....####..#.##.#.#.##.", ".###..#.....#......#...####....",
    "...#.#..#.#..#...#...#....##.##", "..###....#.##.....#..........#.",
    "###...#####......##............", "..###.....#........##.#...#..#.",
    "..##.##.#.....##........##..#.#", "##..#.#...#.#..#..###.#....#..#",
    "....#..#.#.....#..#####...#....", "....#.........#......##.##.....",
    ".#...####.##......##..##.#..#.#", "...#...#.##..#...##..###...#...",
    "###...#.....#.##.###.###..#.#..", "..#......#.###.....#..##.#...#.",
    "#.....##.########...#####....#.", "........##..#..##..##.#........",
    "....#.######....##..#..#.##..#.", "#.......#..##..#..#.#.#..##.##.",
    "...#.#..#..#.......#......###.#", ".#.#..#.#..#.##.#.............#",
    "#....#.##.#.#.....#..#.#..#....", "...###..#...#....#.........#.#.",
    ".#..#.....##..#.#..#.#.......#.", "..#...##...#......#......####..",
    "....#..#.......#.......#.#..#..", "#...#..#...........#.#..#.....#",
    "#...#.#.......#...#....###....#", ".#..#.#.##....#......#........#",
    "..#...#..##..#..#..#..#...#.#..", "..#.#.........#....#....##.....",
    "##.....##.#.#.#.........##.....", ".##...#.##...........#...#...##",
    ".##..##.#.#..........##..##....", "#....#....#.#...#.#..#....#.#..",
    "####....##.....#..##.###.......", "#..#....#......##.#.#....#.....",
    ".....#....#.###.##.........###.", "#.......#.####..#..#..##.......",
    "##.#.......#..##..#....#..#.#..", "..###...#.#...#.....##.##.####.",
    "....#...#.#....#..#..#.....#.##", "#.....##.#.#..#.##..#..##......",
    "................###..#....##...", "..#.##.....#..........##.#...#.",
    "..#.#..#.#....#.#.#..#..#..#.#.", "#...#..##.#.#...#..#...#..#....",
    "#..#.#.........#..###........#.", ".#...#.............#..###..#..#",
    "#.........#.#..#...#.#.....#..#", "....#..#..#.#.#...#...#.....##.",
    "##...###.#.####..#......#...#..", "..#..##...#.#......#.#.......#.",
    "#......###....##.#.##..........", "#####....###..#...............#",
    "##.#...####....#....#...#....#.", ".#.......#..#.....#...#.....###",
    "...#..#.#.#....##......##...#..", "...#.....#...#.##.#..#.#....#..",
    "#...###....#...#.#....#........", ".#.......#........#...##.##.##.",
    ".....#....#...##.....##...###.#", "....#....#.#..#...##.##.##.....",
    ".......#............#...#.#..#.", ".#............#.....##.......#.",
    "........#....#....##......##.##", ".......##..#.#..#.##..###..##.#",
    "#..##..##.........####.#.###...", "#....#..#...##...#.............",
    "#...#...###..........##..#..#..", "....#...#..#.....##...#........",
    "#.....#......#.#.....#...#..#..", "..#.....#.....#....#..#........",
    "..#..#.....#.#.........#..###..", "................###..#.#....#..",
    "#.....#.....#.#.#.#.#..#...#.#.", "#....#....#.#..........#.#....#",
    "....#..#......#..##.#...##.....", "..#.#...#.####....#.#..#.#..#..",
    ".........##......#.....##......", "##.#.###.#.....#.....####.#..#.",
    ".....#.....#..#....#..###.#....", "##..#.#...#.##....#....#.......",
    ".....#......#.#...##..#.#......", "....##..#...#...##..##.#....#.#",
    "............#..........##.#....", "##..#..#.##..##..#.#....#.#.#..",
    ".......#.#...#...#.#...#..#....", "#....#.#...#...#........#..#...",
    "...........#.......#...##..###.", ".#..##......#.##.........##..#.",
    "...#...#...###.#.##....##.#..#.", "#...#..#.#.#.....##..#.......#.",
    ".##..#.###.##......#.#....#.#.#", "..#....#.......#..#..#.#.#.##..",
    "#...#...###...###.........#....", ".#.#...#.....##.#.#..#....#.##.",
    ".........#.#.##.....#.#.###....", "...#.#...#......#...####......#",
    "...##..##....##......##...###..", "###...#..#.......##.....#....#.",
    "...#..#..#..###...##.##..#..#..", "...#......#......##..#.#.##..#.",
    "...#.........#....#.#....#.#...", "##................#..#.#.....#.",
    "....#.##...#..#.##...##.#.....#", "......#..##.##..###.#..#.##.##.",
    ".#.#...###.....###.....##...###", ".##.....#.#.#..#..###..#..#..#.",
    "#.......#..#..#....##.....#....", "...#.#.##..#..#......##.##...#.",
    "....##.#......#...#..#..#......", ".####.#..#.....#..##.#...##..##",
    "..#..#...#..........###..#....#", ".#.#.##.##...#............#....",
    "........##..##......#.##..#.###", "...#.#....###......##.......#..",
    "..##...#...#.#..#.....#.....#..", "##..#...###..#..#.#.#...#...#..",
    ".....#..#....##.....##.....###.", "....##...###.#..#.#....##..#..#",
    "#......#...#....#......#...##..", "....#.##...#.#......#.#.##...#.",
    ".......#.....#...#####...#.#...", "...#.....##.#............#.....",
    "...#.#........#.#.#..#.........", "....###......#.#.#..#.####.#..#",
    "#.....#.#.#.....#.#.#.....#..#.", "..##.##......#...#.#...........",
    "###..###....#.#####......###...", "..##..............##.#.#....#.#",
    "#..#...#..........#..#.#.#..###", "##.###............#....#.#...#.",
    "#.#..#.#..##.#.#....#...#......", "#....#...#..##.....#..#.#..###.",
    "..#.....#.#....#.#..#.##.#..##.", "...##...#.#.##...#....###....#.",
    "......###.####.......#..#.#.#.#", ".#..............##........#....",
    "...##.##...##....#..#.......#..", ".....#.....#....###...#..#..#.#",
    ".#.....#..#.....#......#.....##", "#.#.##.#..#..#.....#.##..###...",
    "..#......#...##.###..#.#...#..#", "......#.....#...##......#......",
    "##.#........#..........#.....#.", "#........##.#............##....",
    "...#......##...#.#.....##......", "...##.......#....#.#..#.#.###..",
    "..#....##..##.##.....###....#..", "..#...#.#...#.....#..........#.",
    "......#...#...#.#.##.#...#.#.#.", ".#...#......#.##........#......",
    ".##.##..#....#...#.#...##......", "#..#......#.#...........#....#.",
    "....##.#....#...#..#....#.#..##", "#....##.##....#.#..##.#........",
    ".##.##.#....##.....#..#....#..#", "...#...#.....###.#.##..........",
    "....#...#....##.......###......", "#.........#......#.#.......#...",
    "#..........#..##..#.#..........", ".....#.......#..##.##....##...#",
    "........................#.#....", "#..#.........#.............#..#",
    "#..#.....#.......#....#....#.#.", "..##..##.......##....#...#.....",
    ".##......#..##......#.###......", "...#.#........#.......##..###..",
    "..##...###.###......#...#....##", "#...#...#.....###.#.#.#..#.....",
    "#....#.........#..##...#...##..", "#..###..#.#.#.##.#..#.#....#.##",
    "#...#.#.....#.###.#.......#....", "..##..#..#....#.#...........#.#",
    "#.........#.#......#...##......", ".######......#..#....#.#.#....#",
    "##..#.#..####.###.........#....", "###########.....##.##...#..#...",
    "#...##.#.#....#.#....#......#..", "...#..##..#..##..#......#....#.",
    ".#....#...#....#.#..##....##...", "#..#.#............#....#.#...#.",
    "...#...#..#.#.##......#..#.#...", "#.#...##.....#..#.##......####.",
    ".#.#..##..#.....#.#..#.##......", "#.#.##......##.....#..#.#..#...",
    "#..##...#.##.#.......#.##......", "..#.......#.#.#...##..##...#...",
    ".#...#..#..#.#.........#..##...", "#..#.......#....#.#...#.###...#",
    ".......#..#.......##.#.#...#.#.", ".#.................###.#..###..",
    "..........#.#.....##..#####...#", "#......#.#..##.#.#...#.##.#....",
    "#......#.#..##.##.#...#....#...", "....#..#......#....#....#######",
    ".#...#......#....###......#.###", "#.#....#.#...#.###......#..#..#",
    ".###......#.#...#.####.#..####.", "######.#.....###.#...#.#.....#.",
    ".#.###....#..#.#.....#.....####", ".......###.#.........#..#......",
    "#...#.....##.#......####.......", "..#.#..##.#.#...#...#..##..##..",
    ".....#...##.....#...##......##.", "##..#..#.##..#.#......#.....#..",
    "##.........#.#.##.#..#.#....#.#", ".#........###...#.........#....",
    "...#..#.#..#....####...........", "#.#....#..##..####.#...#.##....",
    ".#.....#.......#..........#..##", "...#.......#...###..#.....#..##",
    ".........#.###.#..##...#.##...#", ".#..........##..####...#..#.#.#",
    ".#...##...#............##...#.#", "...#....#.#..........#.#..#.#..",
    ".#.#...##....##.#.#.#....#.....", "....#..#.....#.#..#.#..#.##.###",
    ".....#.#.....#..#......#.#.#...", ".....#.#.#..###..#.#..###...#..",
    "#.......####...#.#..#......##.#", "....#..#..###......###.##....#.",
    "##.....#.....#.............#..#", "#..#..#...##.....##..#..#.#....",
    ".....#.#.###...#...............", "#.#.#.....#.#..#.#...#.......#.",
    "..##.##............#....#..##..", "#....##...#.....#.###...#.#....",
    "#...##.#.........#...#....#....", "##.##.#...#.#...###..#....##..#",
    "....#....##..#..#.......#...##.", ".#...#...#..#.....#..###.#..#.#",
    "....#..###......#....##....#...", "#.#.....#....##.#..#.#...###...",
    ".......#............#......#...", ".##..#.###.#.............###...",
    "..##...##.#.#.#.....#........##", "....#.###....#..#..#...#...#..#",
    ".....#...#...#..#....#.....##..", "###.#.#.....#......####.....#..",
    "#.#.###............#......#....", "..#.....#..#..#..#....#......#.",
    "#...######...#....#.##...##.#.#", "##.#.#.#..##......##.#..#.#...#",
    "............#.#..#.##....#.....", "......#............#.#...#..#.#",
    ".#..##...##..#.#.#..###.....##.", "#.###.#...........#...#....#...",
    "....##.....#...##...#...###.#.#", ".####.#.#.....#.#..#.#.##......",
    ".#...##......###...#..##..#.#..", ".#......#...#....##.....##..#..",
    "..........##.....###.##.#...#.#", ".#........##.#..............#..",
    "#...###..#...#.....#....#.....#", "...#......#..#...#...#..###.#..",
    ".#...##..#........#.......#.#..", ".#.#.##.........##.##......#..#",
    "#...#.#.#...#.....#.#...#.#..#.", "#.#..#...#...#...##..........#.",
    ".#...........#....#..#.#..#.#..", "#.......#......#..#...#........",
    ".....#..#...##..###..##........", "......#...#.....#..#.#.#....##.",
    "....##..##..##....###.##.......", ".#........##.#.#...#..#........",
    ".....##...##...#......#..#...#.", "..#.....#....###.#..##....#..#.",
    "......#..#...####.#.....##.####",
};
} // namespace input