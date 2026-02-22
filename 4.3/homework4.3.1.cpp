#include <iostream>
#include <iomanip>
#include <vector>


template <class Type>
Type squaring(Type a) {
	return a * a;
}

template <class Type>
std::vector<Type> squaring(std::vector<Type>& a) {
	int vec_size = a.size();
	for (int i = 0; i < vec_size; i++) {
		a[i] = a[i] * a[i];
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int a = 4;
	std::cout << "[IN]: " << a << std::endl;
	std::cout << "[OUT]: " << squaring(a) << std::endl;

	std::vector<int> my_vector{ -1, 4, 8 };
	int vec_size = my_vector.size();
	std::cout << "[IN]: ";
	for (int i = 0; i < vec_size; i++) {
		if (i == 0) {
			std::cout << my_vector[i];
		}
		else {
			std::cout << ", " << my_vector[i];
		}
	}
	std::cout << std::endl;

	squaring(my_vector);

	std::cout << "[OUT]: ";
	for (int i = 0; i < vec_size; i++) {
		if (i == 0) {
			std::cout << my_vector[i];
		}
		else {
			std::cout << ", " << my_vector[i];
		}
	}
	std::cout << std::endl;

	return 0;

}


