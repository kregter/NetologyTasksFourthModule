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
	smart_array& operator=(const smart_array& other);
	
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

smart_array& smart_array::operator=(const smart_array& other) {
	delete[] m_array;
	m_size = other.m_size;
	m_index = other.m_index;
	m_array = new int[m_size];
	for (int i = 0; i < m_index; ++i) {
		m_array[i] = other.m_array[i];
	}
	return *this;
}


int main()
{
	setlocale(LC_ALL, "rus");

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(133);
		arr.add_element(90);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}


	return 0;

}


