#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
    int data[SIZE][SIZE]; // 2D array for matrix data

public:
    // 1. Read values from a file into a matrix
    void readFromFile(const string& filename, bool isFirstMatrix);
    
    // 2. Display a matrix
    void display() const;
    
    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix& other) const;
    
    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other) const;
    
    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const;
    
    // 6. Swap matrix rows
    void swapRows(int row1, int row2);
};

void Matrix::readFromFile(const string& filename, bool isFirstMatrix) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    int filler[SIZE][SIZE];
    int startRow = isFirstMatrix ? 0 : SIZE;
    for (int i; i < startRow + SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (startRow == 0){
                file >> data[i][j];
            }
            else if (startRow == SIZE && i < 4){
                file >> filler[i][j];
            }
            else{
                file >> data[i % SIZE][j]; // Using modulo to cycle through matrix
            }
        }
    }
    
    file.close();
}

void Matrix::display() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << setw(5) << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = data[i][j] * other.data[i][j];
        }
    }
    return result;
}

int Matrix::sumOfDiagonals() const {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += data[i][i];
        sum += data[i][SIZE - 1 - i];
    }
    return sum;
}

void Matrix::swapRows(int row1, int row2) {
    if (row1 < 0 || row1 >= SIZE || row2 < 0 || row2 >= SIZE) {
        cerr << "Invalid row indices" << endl;
        return;
    }
    for (int j = 0; j < SIZE; ++j) {
        swap(data[row1][j], data[row2][j]);
    }
}

int main() {
    Matrix mat1, mat2;
    
    // Read from a single file for both matrices
    mat1.readFromFile("matrix.txt", true); // Read first matrix
    cout << "Matrix 1:" << endl;
    mat1.display();
    
    mat2.readFromFile("matrix.txt", false); // Read second matrix
    cout << "Matrix 2:" << endl;
    mat2.display();
    
    // Add matrices
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();
    
    // Multiply matrices
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();
    
    // Sum of diagonals
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << "\n" << endl;
    
    // Swap rows
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows 0 and 2:" << endl;
    mat1.display();
    
    return 0;
}
