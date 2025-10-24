#include <iostream>
#include <time.h>
using namespace std;

template <class T>
class Matrix {
    T** arr;
    int rows, cols;
public:
    Matrix();
    Matrix(int r, int c, T** a = nullptr);
    Matrix(const Matrix<T>& other); // ✅ копіювальний конструктор
    ~Matrix();
    void Input();
    void RandInput();
    void Output();
    Matrix<T> operator + (const Matrix& obj);
    Matrix<T> operator - (const Matrix& obj);
    Matrix<T> operator * (const Matrix& obj);
    Matrix<T> operator / (const Matrix& obj);
};

template <class T>
Matrix<T>::Matrix() : rows(0), cols(0), arr(nullptr) {}

template <class T>
Matrix<T>::Matrix(int r, int c, T** a) : rows(r), cols(c) {
    arr = new T * [rows];
    for (size_t i = 0; i < rows; i++)
        arr[i] = new T[cols];

    if (a != nullptr) {
        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                arr[i][j] = a[i][j];
    }
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& other) {
    rows = other.rows;
    cols = other.cols;
    arr = new T * [rows];
    for (size_t i = 0; i < rows; i++) {
        arr[i] = new T[cols];
        for (size_t j = 0; j < cols; j++)
            arr[i][j] = other.arr[i][j];
    }
}

template <class T>
Matrix<T>::~Matrix() {
    if (arr != nullptr) {
        for (size_t i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;
        arr = nullptr;
    }
}

template <class T>
void Matrix<T>::Input() {
    for (size_t i = 0; i < rows; i++) {
        cout << "Enter numbers for row " << i + 1 << ": " << endl;
        for (size_t j = 0; j < cols; j++) {
            cout << "col " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }
}

template <class T>
void Matrix<T>::RandInput() {
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            arr[i][j] = rand() % 50;
}

template <class T>
void Matrix<T>::Output() {
    cout << "Matrix (" << rows << "x" << cols << "):" << endl;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix& obj)
{
    if (rows != obj.rows || cols != obj.cols)
    {
        cout << "Warning: matrices have different sizes. Returning original matrix.\n" << endl;
        return *this;
    }

    Matrix<T> newMatrix(rows, cols, nullptr);

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            newMatrix.arr[i][j] = arr[i][j] + obj.arr[i][j];

    return newMatrix;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix& obj)
{
    if (rows != obj.rows || cols != obj.cols)
    {
        cout << "Warning: matrices have different sizes. Returning original matrix.\n" << endl;
        return *this;
    }

    Matrix<T> newMatrix(rows, cols, nullptr);

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            newMatrix.arr[i][j] = arr[i][j] - obj.arr[i][j];

    return newMatrix;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix& obj)
{
    if (rows != obj.rows || cols != obj.cols)
    {
        cout << "Warning: matrices have different sizes. Returning original matrix.\n" << endl;
        return *this;
    }

    Matrix<T> newMatrix(rows, cols, nullptr);

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            newMatrix.arr[i][j] = arr[i][j] * obj.arr[i][j];

    return newMatrix;
}

template<class T>
Matrix<T> Matrix<T>::operator/(const Matrix& obj)
{
    if (rows != obj.rows || cols != obj.cols)
    {
        cout << "Warning: matrices have different sizes. Returning original matrix.\n" << endl;
        return *this;
    }

    Matrix<T> newMatrix(rows, cols, nullptr);

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (obj.arr[i][j] == 0)
            {
                return *this;
            }
            else
            {
                newMatrix.arr[i][j] = arr[i][j] - obj.arr[i][j];
            }
    return newMatrix;
}
