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

    // ����
    int toDays();
    int weekNum();
    int seasonNum();
    void display();
    string dispStr();
    void tomorrow();

    // ���캯��
    dateIn2006() : month(0), day(0), totalDays(0) {}
    dateIn2006(int m, int d) : month(m), day(d) {
        totalDays = toDays();
    }

    // ���������
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

// ������������2��2�շ���33��
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


// ����������2006��1��1�������գ�������1�ܣ�1��2������һ��������2�ܡ�
int dateIn2006::weekNum() {
    return (totalDays - 1) % 7;
}

// ���ؼ��ȡ�
int dateIn2006::seasonNum() {
    return month % 3;
}

// ֱ�Ӵ�ӡ
void dateIn2006::display() {
    cout << year << '-' << month << '-' << day;
}


// ǰ��һ�졣12��31�ջ�ǰ����13��1�գ���13��1�ղ�����ǰ����
void dateIn2006::tomorrow() {
    day += 1;
    if (day > mList[month - 1]) {
        day -= mList[month - 1];
        month += 1;
    }
}

// ����������ͨ�����÷��ظ��ܵ�һ�������
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
    // ��ʱ dateIn2006(m, total) �Ǹ��ܵ�һ������ڣ����������������һ�ܴ������ñ����
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