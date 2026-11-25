// Triangle.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class Triangle {
private:
    double a, b, c;

    static bool isEqual(double x, double y) {
        return fabs(x - y) < 1e-6;
    }

public:
    Triangle(double a = 1, double b = 1, double c = 1) : a(a), b(b), c(c) {}

    void Init(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    bool isTriangle() const {
        return (a > 0 && b > 0 && c > 0) &&
               (a + b > c) && (a + c > b) && (b + c > a);
    }

    double getSideA() const { return a; }
    double getSideB() const { return b; }
    double getSideC() const { return c; }

    void setSideA(double a) {
        if (a <= 0) {
            cout << "Error: side length must be positive, ignored." << endl;
            return;
        }
        this->a = a;
    }

    void setSideB(double b) {
        if (b <= 0) {
            cout << "Error: side length must be positive, ignored." << endl;
            return;
        }
        this->b = b;
    }

    void setSideC(double c) {
        if (c <= 0) {
            cout << "Error: side length must be positive, ignored." << endl;
            return;
        }
        this->c = c;
    }

    double perimeter() const {
        if (!isTriangle()) {
            cout << "Error: cannot form a triangle" << endl;
            return 0.0;
        }
        return a + b + c;
    }

    double area() const {
        if (!isTriangle()) {
            cout << "Error: cannot form a triangle" << endl;
            return 0.0;
        }
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    int typeTriangle() const {
        if (!isTriangle()) return 0;

        double s[3] = {a, b, c};
        sort(s, s + 3); 

        if (isEqual(s[0], s[1]) && isEqual(s[1], s[2])) return 4;

        bool isosceles = isEqual(s[0], s[1]) || isEqual(s[1], s[2]);
        double diff = s[0] * s[0] + s[1] * s[1] - s[2] * s[2];

        if (fabs(diff) < 1e-6) return isosceles ? 5 : 1;
        if (diff > 0)          return isosceles ? 6 : 2;
        return isosceles ? 7 : 3;
    }

    static string typeName(int type) {
        switch (type) {
            case 1: return "直角三角形";
            case 2: return "锐角三角形";
            case 3: return "钝角三角形";
            case 4: return "等边三角形";
            case 5: return "等腰直角三角形";
            case 6: return "等腰锐角三角形";
            case 7: return "等腰钝角三角形";
            default: return "不构成三角形";
        }
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "Sides: " << a << " " << b << " " << c << endl;
        if (!isTriangle()) {
            cout << "Error: cannot form a triangle" << endl;
            return;
        }
        cout << "Perimeter: " << perimeter() << endl;
        cout << "Area: " << area() << endl;
        cout << "Type: " << typeName(typeTriangle()) << endl;
    }
};

int main() {
    double a, b, c;
    if (cin >> a >> b >> c) {
        Triangle t(a, b, c);
        t.display();
    }
    return 0;
}