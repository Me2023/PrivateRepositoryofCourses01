#include "flight.h"
#include "Graph.cpp"
// 由航班列表，不考虑时间先后，形成以城市为顶点、以飞行用时为权值的有向图
MGraph<string, int> FlyingTimeGraph(vector<flight>& fls) {
    int i, j, n = fls.size();
    int numOfV, numOfE;
    vector<string> v; // 储存顶点
    string ed[n][2]; // 储存边
    vector<int> c;  // 储存权值
    for (i = 0; i < n; i++) {
        
        // 正向和反向边及其权值
        ed[i][0] = fls[i].getPos(0);
        ed[i][1] = fls[i].getPos(1);
        c.push_back(fls[i].getInterval());

        // 顶点是否已经被存，一条航班有两个地点，都要进行判断
        for (j = 0; ; j++) {
            if (j == v.size()) {
                v.push_back(fls[i].getPos(0));
                break;
            }
            if (v.at(j) == fls[i].getPos(0)) {
                break;
            }
        }
        for (j = 0; ; j++) {
            if (j == v.size()) {
                v.push_back(fls[i].getPos(1));
                break;
            }
            if (v.at(j) == fls[i].getPos(1)) {
                break;
            }
        }
    }
    numOfV = v.size();
    numOfE = n;
    return MGraph<string, int>(v, ed, c, numOfV, numOfE, 1);    // 构造函数建立图
}

// 由航班列表，不考虑时间先后，形成以城市为顶点、以价格为权值的有向图
MGraph<string, int> CostsGraph(vector<flight>& fls) {
    int i, j, n = fls.size();
    int numOfV, numOfE;
    vector<string> v; // 储存顶点
    string ed[n][2]; // 储存边
    vector<int> c;  // 储存权值
    for (i = 0; i < n; i++) {
        
        // 正向和反向边及其权值
        ed[i][0] = fls[i].getPos(0);
        ed[i][1] = fls[i].getPos(1);
        c.push_back(fls[i].getCost());  // 相比FlyingTimeGraph，只有这一行改了。


        for (j = 0; ; j++) {
            if (j == v.size()) {
                v.push_back(fls[i].getPos(0));
                break;
            }
            if (v.at(j) == fls[i].getPos(0)) {
                break;
            }
        }

        for (j = 0; ; j++) {
            if (j == v.size()) {
                v.push_back(fls[i].getPos(1));
                break;
            }
            if (v.at(j) == fls[i].getPos(1)) {
                break;
            }
        }

    }
    numOfV = v.size();
    numOfE = n;
    return MGraph<string, int>(v, ed, c, numOfV, numOfE, 1);
}

// 由航班列表，不考虑时间先后，形成以城市为顶点、权值均为 1 的有向图
MGraph<string, int> TransGraph(vector<flight>& fls) {
    int i, j, n = fls.size();
    int numOfV, numOfE;
    vector<string> v; // 储存顶点
    string ed[n][2]; // 储存边
    vector<int> c;  // 储存权值
    for (i = 0; i < n; i++) {
        
        // 正向和反向边及其权值
        ed[i][0] = fls[i].getPos(0);
        ed[i][1] = fls[i].getPos(1);
        c.push_back(1);  // 相比FlyingTimeGraph，只有这一行改了。


        for (j = 0; ; j++) {
            if (j == v.size()) {
                v.push_back(fls[i].getPos(0));
                break;
            }
            if (v.at(j) == fls[i].getPos(0)) {
                break;
            }
        }

        for (j = 0; ; j++) {
            if (j == v.size()) {
                v.push_back(fls[i].getPos(1));
                break;
            }
            if (v.at(j) == fls[i].getPos(1)) {
                break;
            }
        }

    }
    numOfV = v.size();
    numOfE = n;
    return MGraph<string, int>(v, ed, c, numOfV, numOfE, 1);
}

// 输入由上面函数建立的图及对应的航班列表，以及在图中的边的两个顶点号，找到对应的航班
flight findFlight(MGraph<string, int>& G, vector<flight>& fls, int i, int j) {
    string pos0 = G.getValue(i);
    string pos1 = G.getValue(j);
    int n = fls.size(); int k;
    for (k = 0; k < n; k++) {
        if (fls[k].getPos(0) == pos0 && fls[k].getPos(1) == pos1) {
            return fls[k];
        }
    }
    cout << "有意料之外的事情发生了" << endl;
    return flight();
}