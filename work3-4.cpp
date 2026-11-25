#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

class Point {
private:
    double x, y, z;

public:
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    void Init(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    void display() const {
        cout << fixed << setprecision(2)
             << "(" << x << ", " << y << ", " << z << ")";
    }

    double distanceTo(const Point &other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    friend double euclideanDistance(const Point &a, const Point &b);
    friend double manhattanDistance(const Point &a, const Point &b);
    friend double chebyshevDistance(const Point &a, const Point &b);
    friend Point midpoint(const Point &a, const Point &b);
    friend double euclideanDistance(const Point &p);
};

double euclideanDistance(const Point &a, const Point &b) {
    double dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double manhattanDistance(const Point &a, const Point &b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y) + fabs(a.z - b.z);
}

double chebyshevDistance(const Point &a, const Point &b) {
    return max(fabs(a.x - b.x), max(fabs(a.y - b.y), fabs(a.z - b.z)));
}

Point midpoint(const Point &a, const Point &b) {
    return Point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0, (a.z + b.z) / 2.0);
}

double euclideanDistance(const Point &p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

int main() {
    double x1, y1, z1, x2, y2, z2;
    if (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2) {
        Point A(x1, y1, z1), B(x2, y2, z2);

        cout << fixed << setprecision(2);
        cout << "A = "; A.display(); cout << endl;
        cout << "B = "; B.display(); cout << endl;
        cout << "Euclidean distance: " << euclideanDistance(A, B) << endl;
        cout << "Manhattan distance: " << manhattanDistance(A, B) << endl;
        cout << "Chebyshev distance: " << chebyshevDistance(A, B) << endl;
        cout << "Midpoint: "; midpoint(A, B).display(); cout << endl;
        cout << "A.distanceTo(B): " << A.distanceTo(B) << endl;
        cout << "Distance from B to origin: " << euclideanDistance(B) << endl;
    }
    return 0;
}