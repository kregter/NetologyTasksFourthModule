#include <iostream>
#include <iomanip>
#include <vector>

template <class T>
class Table {
    int rows, cols;
    T* data;
public:
    Table(int r, int c) : rows(r), cols(c) {
        data = new int[rows * cols] {};
    }

    ~Table() {
        delete[] data;
    }

    int* operator[](int row) {
        return data + row * cols;
    }
};


int main()
{
	setlocale(LC_ALL, "rus");
	
    auto test = Table<int>(2, 2);
    test[0][0] = 4;

    std::cout << test[0][0];

	return 0;

}


