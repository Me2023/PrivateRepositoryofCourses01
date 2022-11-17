// 航班数据
#include "time24.h"
#include <vector>
using namespace std;



class flight {
private:
    string _num;
    string _pos[2];
    time24 _time[2];
    int _cost;

public:
    flight() : _cost(-1) {};
    flight(string num, string pos[2], time24 t[2], int cost) : _num(num), _cost(cost) {
        _pos[0] = pos[0]; _pos[1] = pos[1];
        _time[0] = t[0]; _time[1] = t[1];
    };

    string getNum() {
        return _num;
    }
    string getPos(int i) {
        return _pos[i];
    }
    int getCost() {
        return _cost;
    }
    // 返回从出发时间或到达时间（输入 0 或 1）
    time24 getTime(int i) {
        time24 t = _time[i];
        return t;
    }
    /* ****** 一些计算时间的方法 ****** */
    // 返回出发和到达时间间隔
    int getInterval() {
        time24 dt;
        dt = _time[1] - _time[0]; 
        return dt.toMins();
    }
    // 若该航班之后，可以换乘 other 航班，计算出包括换乘时间的 other 航班到达目的地后总用时。否则返回 maxWeight
    int getIntervalWith(flight& other) {
        time24 dt;
        if (isBefore(other)) {
            dt = other._time[1] - _time[1];
            return dt.toMins();
        }
        return -1;
    }

    /* ****** 一些比大小的方法 ****** */
    // 比较该航班的到达时间是否在另一航班出发时间之前，即在该航班之后是否可以换乘 other 航班
    bool isBefore(flight& other) {
        if (_time[1] < other._time[0]) return true;
        return false;
    }
    // 比较两航班用时。这个最后忘记用了。
    bool usesLessFlyingTime(flight& other) {
        int dt1 = getInterval(); int dt2 = other.getInterval();
        if (dt1 < dt2) return true;
        return false;
    }
    // 比较两航班花费。这个最后也忘记用了。
    bool costsLess(flight& other) {
        if (_cost < other._cost) return true;
        return false;
    }

};