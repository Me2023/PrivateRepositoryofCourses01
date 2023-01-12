#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "dateIn2006.cpp"

using namespace std;

class AQCondition {
public:
    int num;
    string name;
    string primaryPollutant;
    int index;
    string degreeNum;
    string degree;
    dateIn2006 AQCdate;  // 日期

    // 构造函数
    AQCondition() {}
    AQCondition(int num, string name, string prPoll, int index, 
    string degreeNum, string degree, int m, int d) : 
    num(num), name(name), primaryPollutant(prPoll), index(index), 
    degreeNum(degreeNum), degree(degree), AQCdate(m, d) {}

    // 打印
    void display() {
        printf("%d\t%s\t%-12s\t%d\t%s\t%-12s\t%d\t%d\t%d\n", num, name.c_str(), 
        primaryPollutant.c_str(), index, degreeNum.c_str(), 
        degree.c_str(), AQCdate.year, AQCdate.month, AQCdate.day);
    }

};



