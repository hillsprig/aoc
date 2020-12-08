#include <catch2/catch.hpp>

#include "input.h"

#include <algorithm>
#include <array>
#include <fmt/core.h>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <optional>
#include <regex>
#include <sstream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>

namespace {
std::regex inst_regex = std::regex(R"((\S+) (\S+))");

using OpFn = std::function<int(int, int &)>;
struct Instruction {
    std::string op_name;
    OpFn op;
    int arg;
    int dirty = 0;

    int run(int &accumulator) {
        dirty = 1;
        return op(arg, accumulator);
    }
};

using InstructionVector = std::vector<Instruction>;

OpFn nop_op = [](int, int &) -> int { return 1; };
OpFn acc_op = [](int arg, int &accumulator) -> int {
    accumulator += arg;
    return 1;
};
OpFn jmp_op = [](int arg, int &) -> int { return arg; };

OpFn translate_op(std::string const &op) {
    if ("nop" == op) {
        return nop_op;
    } else if ("acc" == op) {
        return acc_op;
    } else if ("jmp" == op) {
        return jmp_op;
    }
    FAIL();
    return OpFn();
}

auto get_inst_vector(std::string input) {
    std::replace(input.begin(), input.end(), '\n', ' ');
    std::vector<std::string> instructions{std::sregex_token_iterator(input.cbegin(), input.cend(), inst_regex, 1),
                                          std::sregex_token_iterator()};
    std::vector<std::string> arg{std::sregex_token_iterator(input.cbegin(), input.cend(), inst_regex, 2),
                                 std::sregex_token_iterator()};

    InstructionVector program;
    std::transform(instructions.cbegin(), instructions.cend(), arg.cbegin(), std::back_inserter(program),
                   [](const std::string lhs, const std::string rhs) {
                       return Instruction{lhs, translate_op(lhs), std::stoi(rhs)};
                   });
    return program;
}

int execute(const std::string &input) {
    InstructionVector program = get_inst_vector(input);
    int accumulator = 0;
    for (size_t instruction_pointer = 0; instruction_pointer < program.size();) {
        if (!program[instruction_pointer].dirty) {
            instruction_pointer += program[instruction_pointer].run(accumulator);
        } else {
            return accumulator;
        }
    }

    return accumulator;
}

bool flip_instruction(Instruction &i) {
    if (i.op_name == "jmp") {
        i.op_name = "nop";
        i.op = nop_op;
        return true;
    } else if (i.op_name == "nop") {
        i.op_name = "jmp";
        i.op = jmp_op;
        return true;
    }
    return false;
}

void clear_dirty(InstructionVector &program) {
    for (auto &i : program) {
        i.dirty = 0;
    }
}

int execute_live_repair(const std::string &input) {
    InstructionVector program = get_inst_vector(input);
    for (auto &i : program) {
        if (!flip_instruction(i)) {
            continue;
        }
        bool terminated_successfully = true;
        int accumulator = 0;
        size_t instruction_pointer = 0;

        while (instruction_pointer < program.size()) {
            if (!program[instruction_pointer].dirty) {
                instruction_pointer += program[instruction_pointer].run(accumulator);
            } else {
                terminated_successfully = false;
                break;
            }
        }
        if (terminated_successfully) {
            return accumulator;
        }
        flip_instruction(i);
        clear_dirty(program);
    }

    return -1;
}

} // namespace

TEST_CASE("day08_1_sample") { REQUIRE(execute(input::sample) == 5); }

TEST_CASE("day08_1_puzzle") { REQUIRE(execute(input::puzzle) == 1134); }

TEST_CASE("day08_2_sample") { REQUIRE(execute_live_repair(input::sample) == 8); }

TEST_CASE("day08_2_puzzle") { REQUIRE(execute_live_repair(input::puzzle) == 1205); }
