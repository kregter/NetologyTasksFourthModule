#include <iostream>
#include <string>
#include <set>


int main()
{
	setlocale(LC_ALL, "rus");

	int num = 0;
	std::cout << "[IN]: " << std::endl;
	std::cin >> num;

	std::set<int> numbers_set{};
	int num_from_console = 0;

	for (int i = 0; i < num; i++) {
		std::cin >> num_from_console;
		numbers_set.insert(num_from_console);
	}

	std::cout << "[OUT]: " << std::endl;

	for (auto num = numbers_set.rbegin(); num != numbers_set.rend(); ++num) {
		std::cout << *num << std::endl;
	}

	return 0;
}