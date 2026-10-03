#include <iostream>
#include <new>

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows and columns: ";
    if (!(std::cin >> rows >> cols)) {
        return 1;
    }
    if (rows <= 0 || cols <= 0) {
        return 1;
    }

    int** matrix = new (std::nothrow) int*[rows];
    if (matrix == nullptr) {
        return 2;
    }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new (std::nothrow) int[cols];
        if (matrix[i] == nullptr) {
            for (int k = 0; k < i; ++k) {
                delete[] matrix[k];
            }
            delete[] matrix;
            return 2;
        }
    }

    std::cout << "Enter the matrix elements: ";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(std::cin >> matrix[i][j])) {
                for (int k = 0; k < rows; ++k) {
                    delete[] matrix[k];
                }
                delete[] matrix;
                return 1;
            }
        }
    }

    std::cout << "Transposed matrix:" << std::endl;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            std::cout << matrix[i][j];
            if (i < rows - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}