#include <iostream>
using namespace std;

class Matrix {
    int **value;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        value = new int*[rows];
        for (int i = 0; i < rows; i++) {
            value[i] = new int[cols];
        }
    }
    Matrix(const Matrix &other){
        this->rows =other.rows;
        this->cols =other.cols;

        value = new int*[rows];
        for(int i=0;i<rows;i++){
            value[i]=new int[cols];
            for(int j=0;j<cols;j++){
                value[i][j]=other.value[i][j];
            }
        }
    }
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] value[i];
        }
        delete[] value;
    }

    void initialize(const string& name) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter value for " << name << " for row " << i + 1 << ", col " << j + 1 << ": ";
                cin >> value[i][j];
            }
        }
    }


    Matrix add(const Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Addition not possible" << endl;
            return *this;
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.value[i][j] = value[i][j] + other.value[i][j];
            }
        }
        return result;
    }

    
    Matrix subtract(const Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Subtraction not possible" << endl;
            return *this; 
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.value[i][j] = value[i][j] - other.value[i][j];
            }
        }
        return result;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << value[i][j]<<" ";
            }
            cout << endl;
        }
    }
};

int main() {
    int r = 2, c = 2;
    Matrix m1(r, c);
    Matrix m2(r, c);

    m1.initialize("Matrix 1");
    m2.initialize("Matrix 2");

    Matrix additionResult = m1.add(m2);
    Matrix subtractionResult = m1.subtract(m2);

    cout << "\nAddition:\n";
    additionResult.display();

    cout << "\nSubtraction\n";
    subtractionResult.display();

    return 0;
}
