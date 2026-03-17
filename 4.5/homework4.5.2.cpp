#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <algorithm>

template <class Type>
void print_container(Type container) {
	for (auto it : container) {
		std::cout << it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set); // four one three two. помните почему такой порядок? :)

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list); // one, two, three, four

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector); // one, two, three, four

	return 0;
}