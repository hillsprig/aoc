#include <iostream>
#include <array>
#include <vector>
#include <functional>
#include <random>

constexpr int day1(int mass) {
	return (mass / 3) - 2;
}

std::array<int, 3> day2(std::vector<int> input) {
	if (4 > input.size()) {
		return { -1, -1, -1 };
	}

	input[1] = std::rand() % 100;
	input[2] = std::rand() % 100;

	for (int i = 0; i < input.size(); i += 4) {
		std::function<int(int, int)> op;
		if (1 == input[i]) {
			op = std::plus<int>();
		}
		else if (2 == input[i]) {
			op = std::multiplies<int>();
		}
		else if (99 == input[i]) {
			break;
		}
		else {
			std::cerr << "error" << std::endl;
			return { -1, -1, -1 };
		}
		input[input[i + 3]] = op(input[input[i + 1]], input[input[i + 2]]);
	}
	for (auto i : input) {
		std::cout << i << ",";
	}
	std::cout << std::endl;

	std::cout << input[1] << " " << input[2] << std::endl;
	return { input[0], input[1], input[2] };
}

int main()
{
	// day1
	auto day1_input = { 68936, 53526, 62556, 115539, 119659, 77887, 101443, 71392, 130327, 56769, 55083, 101448, 63985, 60433, 80302, 101264, 134416, 112047, 143310, 73842, 124020, 50346, 124192, 119547, 59351, 122161, 103742, 107648, 132879, 65047, 70234, 54569, 72785, 120259, 134533, 61778, 89183, 144270, 68600, 134849, 120221, 126887, 128483, 101293, 78066, 141762, 101929, 119173, 148580, 142710, 142029, 61303, 133204, 120872, 141111, 124900, 73600, 73552, 138183, 147019, 63157, 127712, 83610, 59098, 101675, 57951, 146696, 135604, 75158, 140629, 106125, 142451, 59468, 69078, 115676, 69763, 129999, 97987, 64654, 104168, 67894, 92675, 125475, 110450, 52738, 87569, 91939, 117714, 121018, 140534, 97876, 146651, 105741, 140417, 74771, 141727, 94957, 145126, 61429, 143890 };
	auto day1_result = 0;
	std::function<int(int)> func;
	func = [&func](int mass) -> int {
		int fuel = (mass / 3) - 2;
		if (0 >= fuel) {
			return 0;
		}
		else {
			return fuel + func(fuel);
		}
	};
	std::cout << func(100756) << std::endl;

	for (int i : day1_input) {
		day1_result += (i / 3) - 2;
	}
	std::cout << "day1 " << day1_result << std::endl;

	auto day1_result2 = 0;
	for (int i : day1_input) {
		day1_result2 += func(i);
	}
	std::cout << "day1 " << day1_result2 << std::endl;

	// day2
	// while (19690720 != day2({ 1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,19,1,6,19,23,1,10,23,27,2,27,13,31,1,31,6,35,2,6,35,39,1,39,5,43,1,6,43,47,2,6,47,51,1,51,5,55,2,55,9,59,1,6,59,63,1,9,63,67,1,67,10,71,2,9,71,75,1,6,75,79,1,5,79,83,2,83,10,87,1,87,5,91,1,91,9,95,1,6,95,99,2,99,10,103,1,103,5,107,2,107,6,111,1,111,5,115,1,9,115,119,2,119,10,123,1,6,123,127,2,13,127,131,1,131,6,135,1,135,10,139,1,13,139,143,1,143,13,147,1,5,147,151,1,151,2,155,1,155,5,0,99,2,0,14,0 })[0]);
}
