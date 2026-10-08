#include <iostream>
#include <new>
#include <cstddef>


int inputMatrix(int **matrix, size_t &rows, size_t &cols)
{
    std::cout << "Enter the number of rows and columns: ";
    if (!(std::cin >> rows >> cols)) {
        return 1;
    }
    if (rows == 0 || cols == 0) {
        return 1;
    }

    std::cout << "Enter the matrix elements: ";
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (!(std::cin >> matrix[i][j])) {
                return 1;
            }
        }
    }
    return 0;
}

void outputTransposed(int **matrix, size_t rows, size_t cols)
{
    std::cout << "Transposed matrix:" << std::endl;
    for (size_t j = 0; j < cols; ++j) {
        for (size_t i = 0; i < rows; ++i) {
            std::cout << matrix[i][j];
            if (i < rows - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    size_t rows = 0, cols = 0;

    std::cout << "Enter the number of rows and columns: ";
    if (!(std::cin >> rows >> cols) || rows == 0 || cols == 0) {
        return 1;
    }

    int **matrix = new (std::nothrow) int *[rows];
    if (matrix == nullptr) {
        return 2;
    }
    for (size_t i = 0; i < rows; ++i) {
        matrix[i] = new (std::nothrow) int[cols];
        if (matrix[i] == nullptr) {
            for (size_t k = 0; k < i; ++k) delete[] matrix[k];
            delete[] matrix;
            return 2;
        }
    }

    
    int result = inputMatrix(matrix, rows, cols);
    if (result != 0) {
        for (size_t i = 0; i < rows; ++i) delete[] matrix[i];
        delete[] matrix;
        return result;
    }

    outputTransposed(matrix, rows, cols);

    for (size_t i = 0; i < rows; ++i) delete[] matrix[i];
    delete[] matrix;

    return 0;
}