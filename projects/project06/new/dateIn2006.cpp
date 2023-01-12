#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::cout;  using std::endl;
using std::vector;

class dateIn2006 {
public:
    int year = 2006;
    int month;
    int day;
    int totalDays;
    
    int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 方法
    int toDays();
    int weekNum();
    int seasonNum();
    void display();
    string dispStr();
    void tomorrow();

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
    cout << year << '-' << month << '-' << day;
}


// 前进一天。12月31日会前进到13月1日，但13月1日不可再前进。
void dateIn2006::tomorrow() {
    day += 1;
    if (day > mList[month - 1]) {
        day -= mList[month - 1];
        month += 1;
    }
}

// 输入周数，通过引用返回该周第一天的日期
void daysOfWeek(int w, vector<dateIn2006> &daysInWeek) {

    if (w == 1) {
        daysInWeek.push_back(dateIn2006(1, 1));
        return;
    }
    int total = (w-1) * 7 - 5;
    int mList[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m = 1;
    while(total > mList[m - 1]) {
        total -= mList[m - 1];
        m += 1;
    }
    // 此时 dateIn2006(m, total) 是该周第一天的日期，将包括这天的连续一周存入引用变量里。
    dateIn2006 myDate = dateIn2006(m, total);
    int i = 0;
    for(i = 0; i < 7; i++) {
        if (myDate.month != 13) {
            daysInWeek.push_back(myDate);
            myDate.tomorrow();
        }
    }
    return;
}