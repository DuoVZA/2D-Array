#include "ArrayClass.h"
#include <iostream>
#include <time.h>
using namespace std;

template <class T>
ostream& operator << (ostream& os, Matrix<T>& obj)
{
    os << "Matrix (" << obj.rows << "x" << obj.cols << "):" << endl;
    for (size_t i = 0; i < obj.rows; i++) {
        for (size_t j = 0; j <obj.cols; j++)
            cout << obj.arr[i][j] << "\t";
        cout << endl;
    }
    return os;
}

template <class T>
istream& operator>> (istream& is, Matrix<T>& obj)
{
    for (size_t i = 0; i < obj.rows; i++) {
        cout << "Enter numbers for row " << i + 1 << ": " << endl;
        for (size_t j = 0; j < obj.cols; j++) {
            cout << "col " << j + 1 << ": ";
            is >> obj.arr[i][j];
        }
    }
    return is;
}

int main()
{
    srand(time(NULL));

    Matrix<int> obj(2, 2);
    Matrix<int> obj1(2, 2);

    cout << "Matrix 1:" << endl;
    obj.Input();
    obj.Output();

    cout << "\nMatrix 2:" << endl;
    obj1.RandInput();
    obj1.Output();

    cout << "\nMatrix 3 = Matrix1 + Matrix2:\n";
    Matrix<int> obj3 = obj + obj1;
    Matrix<int> obj4 = obj / obj1;
    obj3.Output();
    obj4.Output();

    Matrix<Point> obj5(3, 3);

    cin >> obj5;

    return 0;

}