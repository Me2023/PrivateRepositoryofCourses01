#include "DatasAndFinalFunction.cpp"


int main() {
    string start, dest;
    cout << "请输入出发地和到达地，中间以空格隔开" << endl;
    cin >> start >> dest;
    cout << "从 " << start << " 到 " << dest << " 有如下最优方案及相应花费：" << endl;
    cout << "飞行时间最短：" << endl;
    minFlyingTime(start, dest);
    cout << "总用时最短：" << endl;
    minTotalTime(start, dest);
    cout << "费用最低：" << endl;
    minCost(start, dest);
    cout << "中转次数最少：" << endl;
    minTrans(start, dest);
}




