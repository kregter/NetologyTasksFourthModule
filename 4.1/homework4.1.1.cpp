#include <iostream>
#include <iomanip>

class my_exception : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Ошибка!";
	}
};

class smart_array {
private:
	int* m_array;
	int m_size;
	int m_index = 0;

public:
	void add_element(int element);
	int get_element(int index);
	
	smart_array(int size) {
		m_size = size;
		m_array = new int[m_size];
	}

	~smart_array() {
		delete[] m_array;
	}
};

void smart_array::add_element(int element) {
	if (m_index == m_size) {
		throw my_exception();
	}
	m_array[m_index] = element;
	m_index++;
}

int smart_array::get_element(int index) {
	if (index < 0 || index >= m_size) {
		throw my_exception();
	}
	return m_array[index];
}



int main()
{
	setlocale(LC_ALL, "rus");

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}


	return 0;

}


