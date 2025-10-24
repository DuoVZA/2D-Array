#include "ArrayClass.h"
#include <iostream>
#include <time.h>
using namespace std;

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

    return 0;
}