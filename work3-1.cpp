// Date.cpp
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

    static bool isLeap(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    static int daysInMonth(int y, int m) {
        static const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m < 1 || m > 12) return 0;
        if (m == 2 && isLeap(y)) return 29;
        return days[m];
    }

    static bool isValidDate(int y, int m, int d) {
        if (y < 1 || m < 1 || m > 12) return false;
        return d >= 1 && d <= daysInMonth(y, m);
    }

public:
    Date(int y = 1900, int m = 1, int d = 1) : year(y), month(m), day(d) {
        if (!isValidDate(year, month, day)) {
            cout << "Error: invalid date (" << y << "-" << m << "-" << d
                 << "), reset to default 1900-01-01." << endl;
            year = 1900;
            month = 1;
            day = 1;
        }
    }

    void Init(int y, int m, int d) {
        if (!isValidDate(y, m, d)) {
            cout << "Error: invalid date (" << y << "-" << m << "-" << d
                 << "), reset to default 1900-01-01." << endl;
            year = 1900;
            month = 1;
            day = 1;
        } else {
            year = y;
            month = m;
            day = d;
        }
    }

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    void setYear(int y) {
        if (!isValidDate(y, month, day)) {
            cout << "Error: invalid year " << y << ", ignored." << endl;
            return;
        }
        year = y;
    }

    void setMonth(int m) {
        if (!isValidDate(year, m, day)) {
            cout << "Error: invalid month " << m << ", ignored." << endl;
            return;
        }
        month = m;
    }

    void setDay(int d) {
        if (!isValidDate(year, month, d)) {
            cout << "Error: invalid day " << d << ", ignored." << endl;
            return;
        }
        day = d;
    }

    void display() const {
        cout << setfill('0')
             << setw(4) << year << "-"
             << setw(2) << month << "-"
             << setw(2) << day << setfill(' ');
    }

    int calWeekday() const {
        int y = year, m = month, d = day;
        if (m == 1 || m == 2) {
            m += 12;
            y -= 1;
        }
        return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
    }

    bool isLeapYear() const {
        return isLeap(year);
    }

    void nextDay() {
        day++;
        if (day > daysInMonth(year, month)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
};

string weekdayToString(int w) {
    static const string names[7] = {
        "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"
    };
    return (w >= 0 && w <= 6) ? names[w] : "未知";
}

int main() {
    int y, m, d;
    if (cin >> y >> m >> d) {
        Date dt(y, m, d);
        cout << "Date: ";
        dt.display();
        cout << endl;
        cout << "Weekday: " << weekdayToString(dt.calWeekday()) << endl;
        cout << "Leap year: " << (dt.isLeapYear() ? "Yes" : "No") << endl;
        dt.nextDay();
        cout << "Next day: ";
        dt.display();
        cout << endl;
    }
    return 0;
}