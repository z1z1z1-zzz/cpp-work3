#include "MyArray.h"
#include <iostream>

using namespace std;

int main() {
    MyArray A(3), B(3);
    A.set(0, 6); A.set(1, 8); A.set(2, 9);
    B.set(0, 3); B.set(1, 2); B.set(2, 4);

    cout << "A = "; A.display(); cout << endl;
    cout << "B = "; B.display(); cout << endl;
    cout << "A merge B = "; A.merge(B).display(); cout << endl;
    cout << "A + B = "; A.add(B).display(); cout << endl;
    cout << "A - B = "; A.subtract(B).display(); cout << endl;
    cout << "A * B = "; A.multiply(B).display(); cout << endl;
    cout << "A / B = "; A.divide(B).display(); cout << endl;

    MyArray C(3), D(2);
    C.set(0, 1); C.set(1, 2); C.set(2, 3);
    D.set(0, 4); D.set(1, 5);
    cout << "\nC = "; C.display(); cout << endl;
    cout << "D = "; D.display(); cout << endl;
    MyArray sumCD = C.add(D);
    cout << "C + D = "; sumCD.display(); cout << endl;

    MyArray E = A;
    E.set(0, 99);
    cout << "\nÐÞ¸Ä E[0] = 99 ºó£º" << endl;
    cout << "E = "; E.display(); cout << endl;
    cout << "A = "; A.display(); cout << endl;

    MyArray emptyArr;
    cout << "\nEmpty = "; emptyArr.display(); cout << endl;
    A.set(5, 100);
    MyArray zeroArr(3, 0);
    MyArray divRes = A.divide(zeroArr);
    cout << "A / zeroArr = "; divRes.display(); cout << endl;

    return 0;
}