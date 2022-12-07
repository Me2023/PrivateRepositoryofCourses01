#include <string>
#include <iostream>
using std::string;
using std::cout;  using std::endl;

class dateIn2006 {
public:
    int year = 2006;
    int month;
    int day;
    int totalDays;
    

    int toDays();
    int weekNum();
    int seasonNum();
    void display();
    string dispStr();

    // 构造函数
    dateIn2006() : month(0), day(0), totalDays(0) {}
    dateIn2006(int m, int d) : month(m), day(d) {
        totalDays = toDays();
    }

    // 运算符重载
    bool operator<(dateIn2006 &other) {
        if (totalDays < other.totalDays) return true;
        return false;
    }
    bool operator>(dateIn2006 &other) {
        if (totalDays > other.totalDays) return true;
        return false;
    }
    bool operator==(dateIn2006 &other) {
        if (totalDays < other.totalDays) return true;
        return false;
    }
    
};

// 返回天数。如2月2日返回33。
int dateIn2006::toDays() {
    int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = month;
    int days = 0;
    while (i > 0) {
        days += mList[i-1];
        i--;
    }
    days += day;
    return days;
}

// 返回周数。2006年1月1日是周日，算作第1周；1月2日是周一，算作第2周。
int dateIn2006::weekNum() {
    return (totalDays - 1) % 7;
}


// 返回季度。
int dateIn2006::seasonNum() {
    return month % 3;
}

// 直接打印
void dateIn2006::display() {
    cout << year << '-' << month << '-' << day << endl;
}

// 返回要打印的字符串
string dateIn2006::dispStr() {
    return "" + year + '-' + month + '-' + day;
    // return year + '-' + month + '-' + day; 会被当做int，无法返回
}