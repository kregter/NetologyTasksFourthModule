#include <iostream>
#include <vector>

template <class T>
class Table {
private:
    int rows_, cols_;
    std::vector<std::vector<T>> data_;
public:
    Table(int r, int c) : rows_(r), cols_(c) {
        data_.resize(rows_);
        for (int i = 0; i < rows_; i++) {
            data_[i].resize(cols_);
        }
    }

    const std::vector<T> operator[] (int row) const {
        if (row >= rows_ || row < 0) {
            throw std::out_of_range("Rows out of range");
        }
        return data_[row];
    }

    std::vector<T>& operator[] (int row) {
        if (row >= rows_ || row < 0) {
            throw std::out_of_range("Rows out of range");
        }
        return data_[row];
    }

    int Size() const {
        return rows_ * cols_;
    }
};


int main()
{
	setlocale(LC_ALL, "rus");
    try {
        Table<int> test(3, 3);
        test[0][0] = 4;

        std::cout << test.Size() << std::endl;

        std::cout << test[0][0];
    }
    catch(std::exception e) {
        std::cout << e.what() << std::endl;
    }
    
	return 0;

}
