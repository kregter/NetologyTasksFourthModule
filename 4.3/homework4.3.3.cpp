#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

class functor_learn {
private: 
	int m_sum = 0;
	int m_counter = 0;
public:
	void operator()(int number) {
		if ((number % 3) == 0) {
			m_sum += number;
			m_counter++;
		}
	}

	int get_sum() {
		return m_sum;
	}

	int get_count() {
		return m_counter;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	
	std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };

	int vec_size = numbers.size();
	std::cout << "[IN]: ";
	for (int i = 0; i < vec_size; i++) {
		if (i == 0) {
			std::cout << numbers[i];
		}
		else {
			std::cout << ", " << numbers[i];
		}
	}
	std::cout << std::endl;

	functor_learn functor = std::for_each(numbers.begin(), numbers.end(), functor_learn());
	std::cout << "[OUT]: get_sum() = " << functor.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << functor.get_count() << std::endl;

	return 0;

}


