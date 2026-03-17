#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	setlocale(LC_ALL, "rus");

	std::vector<int> numbers {1, 1, 2, 5, 6, 1, 2, 4};

	std::cout << "[IN]: ";
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::sort(numbers.begin(), numbers.end());

	auto it = std::unique(numbers.begin(), numbers.end());

	numbers.erase(it, numbers.end());

	std::cout << "[OUT]: ";
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}