// 24小时制时间
#include <string>
#include <iostream>
using namespace std;

class time24 {
private:
    int hour;
    int minute;

public:
    // 构造函数
    time24() : hour(0), minute(0) {}
    time24(int h, int m) : hour(h), minute(m) {}
    // 运算符重载
    time24 operator+(time24 const& other);
    time24 operator-(time24 const& other);
    bool operator<(time24 const& other);
    bool operator>(time24 const& other);
    void Display() {
        cout << hour << ':' << minute << endl; 
    }
    // 转化为分钟，例如 2:45 转化为 165
    int toMins() {
        return hour * 60 + minute;
    }
};

time24 time24::operator+(time24 const& other) {
    int m = minute + other.minute;
    int h = hour + other.hour;
    if (m >= 60) {
        m = m - 60;
        h += 1;
    }
    return time24(h, m);
}

time24 time24::operator-(time24 const& other) {
    int m = minute - other.minute;
    int h = hour - other.hour;
    if (m < 0) {
        m = m + 60;
        h -= 1;
    }
    return time24(h, m);
}

bool time24::operator<(time24 const& other) {
    if (hour > other.hour) return false;
    else if (hour == other.hour) {
        if (minute >= other.hour) return false;
    }
    return true;
}

bool time24::operator>(time24 const& other) {
    if (hour < other.hour) return false;
    else if (hour == other.hour) {
        if (minute <= other.hour) return false;
    }
    return true;
}