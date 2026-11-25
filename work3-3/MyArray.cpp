#include "MyArray.h"
#include <iostream>
#include <algorithm>

using namespace std;

MyArray::MyArray() : p(nullptr), N(0) {}

MyArray::MyArray(int n, int value) {
    if (n <= 0) {
        p = nullptr;
        N = 0;
    }
    else {
        N = n;
        p = new int[N];
        for (int i = 0; i < N; ++i) p[i] = value;
    }
}

MyArray::MyArray(const MyArray& other) {
    N = other.N;
    if (N > 0 && other.p != nullptr) {
        p = new int[N];
        for (int i = 0; i < N; ++i) p[i] = other.p[i];
    }
    else {
        p = nullptr;
        N = 0;
    }
}

MyArray& MyArray::operator=(const MyArray& other) {
    if (this == &other) return *this;
    delete[] p;
    N = other.N;
    if (N > 0 && other.p != nullptr) {
        p = new int[N];
        for (int i = 0; i < N; ++i) p[i] = other.p[i];
    }
    else {
        p = nullptr;
        N = 0;
    }
    return *this;
}

MyArray::~MyArray() {
    delete[] p;
    p = nullptr;
    N = 0;
}

int MyArray::size() const { return N; }

int MyArray::get(int index) const {
    if (index < 0 || index >= N) {
        cout << "Error: index " << index << " out of range [0, " << N - 1 << "]" << endl;
        return 0;
    }
    return p[index];
}

void MyArray::set(int index, int value) {
    if (index < 0 || index >= N) {
        cout << "Error: index " << index << " out of range [0, " << N - 1 << "], ignored." << endl;
        return;
    }
    p[index] = value;
}

void MyArray::display() const {
    cout << "{";
    for (int i = 0; i < N; ++i) {
        cout << p[i];
        if (i < N - 1) cout << ", ";
    }
    cout << "}";
}

MyArray MyArray::merge(const MyArray& other) const {
    MyArray res(N + other.N);
    for (int i = 0; i < N; ++i) res.p[i] = p[i];
    for (int i = 0; i < other.N; ++i) res.p[N + i] = other.p[i];
    return res;
}

MyArray MyArray::add(const MyArray& other) const {
    int len = min(N, other.N);
    if (N != other.N) {
        cout << "Warning: different sizes (" << N << " vs " << other.N
            << "), use the shorter one" << endl;
    }
    MyArray res(len);
    for (int i = 0; i < len; ++i) res.p[i] = p[i] + other.p[i];
    return res;
}

MyArray MyArray::subtract(const MyArray& other) const {
    int len = min(N, other.N);
    if (N != other.N) {
        cout << "Warning: different sizes (" << N << " vs " << other.N
            << "), use the shorter one" << endl;
    }
    MyArray res(len);
    for (int i = 0; i < len; ++i) res.p[i] = p[i] - other.p[i];
    return res;
}

MyArray MyArray::multiply(const MyArray& other) const {
    int len = min(N, other.N);
    if (N != other.N) {
        cout << "Warning: different sizes (" << N << " vs " << other.N
            << "), use the shorter one" << endl;
    }
    MyArray res(len);
    for (int i = 0; i < len; ++i) res.p[i] = p[i] * other.p[i];
    return res;
}

MyArray MyArray::divide(const MyArray& other) const {
    int len = min(N, other.N);
    if (N != other.N) {
        cout << "Warning: different sizes (" << N << " vs " << other.N
            << "), use the shorter one" << endl;
    }
    MyArray res(len);
    for (int i = 0; i < len; ++i) {
        if (other.p[i] == 0) {
            cout << "Warning: division by zero at index " << i << ", set result to 0." << endl;
            res.p[i] = 0;
        }
        else {
            res.p[i] = p[i] / other.p[i];
        }
    }
    return res;
}