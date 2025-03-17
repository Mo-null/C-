#include <iostream>
#include <vector>
using namespace std;

// Matrix class
class Matrix {
private:
    int rows, cols;
    vector<vector<int>> data;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c)) {}

    // Function to input matrix elements
    void input() {
        cout << "Enter matrix elements (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Function to display matrix
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to add two matrices
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices are incompatible for addition!");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Function to multiply two matrices
    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrices are incompatible for multiplication!");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Function to compute transpose of a matrix
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
};

int main() {
    int choice;
    int rows1, cols1, rows2, cols2;

    cout << "Enter dimensions of the first matrix (rows columns): ";
    cin >> rows1 >> cols1;
    Matrix mat1(rows1, cols1);
    mat1.input();

    cout << "Enter dimensions of the second matrix (rows columns): ";
    cin >> rows2 >> cols2;
    Matrix mat2(rows2, cols2);
    mat2.input();

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Sum of two matrices\n";
        cout << "2. Product of two matrices\n";
        cout << "3. Transpose of a matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    Matrix sum = mat1.add(mat2);
                    cout << "Sum of the matrices:\n";
                    sum.display();
                    break;
                }
                case 2: {
                    Matrix product = mat1.multiply(mat2);
                    cout << "Product of the matrices:\n";
                    product.display();
                    break;
                }
                case 3: {
                    cout << "Transpose of which matrix? (1 or 2): ";
                    int matChoice;
                    cin >> matChoice;
                    if (matChoice == 1) {
                        Matrix transpose = mat1.transpose();
                        cout << "Transpose of matrix 1:\n";
                        transpose.display();
                    } else if (matChoice == 2) {
                        Matrix transpose = mat2.transpose();
                        cout << "Transpose of matrix 2:\n";
                        transpose.display();
                    } else {
                        cout << "Invalid choice!\n";
                    }
                    break;
                }
                case 4:
                    cout << "Exiting...\n";
                    return 0;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
