#include "FlightGraph.cpp"



void ShortestPath(MGraph<string, int>& G, int v, vector<flight>& fls, vector<int>& dist, vector<int>& path) {
// 求顶点 v 到图 G 各顶点的最短路径，通过引用返回 dist[] 和 path[]
// 相比一般的 Dijkstra 算法，多输入了航班列表 vector<flight>& fls，其索引值应与边（和权值）的索引值一致
    int n = G.numberOfVertices();
    int S[maxVertices];                         // 最短路径标记顶点集
    int i, j, k, pre;
    int w, min;
    flight ukFlight;
    // 初始化
    for (i = 0; i < n; i++) {
        dist.push_back(G.getWeight(v, i));      // 路径长度初始化
        S[i] = 0;                               // 标记初始化
        if (i != v && dist[i] < maxWeight) {
            path.push_back(v);                  // 路径数组初始化（v 的邻接顶点）
        }
        else path.push_back(-1);
    }
    S[v] = 1; dist[v] = 0;                      // 到顶点 v 已找到最短路径
    // 逐个求 v 到其他顶点最短路径
    for (i = 0; i < n-1; i++) {
        min = maxWeight; 
        int u = v;                  // 初始化
        // 找不在S中具有最短路径的顶点 u
        for (j = 0; j < n; j++) {
            if (!S[j] && dist[j] < min) {
                u = j;
                min = dist[j];
            }                       
        }                           
        S[u] = 1;                   // 将 u 加入集合 S
        // if (min < maxWeight) cout <<  "到" << G.getValue(u) << "的最短路径" << min << endl;
        /* 下面的循环相比一般的 Dijkstra 算法加入了起飞时间是否允许中转的判定 */
        // 修改经过 u 到其他顶点的路径长度
        k = G.firstNeighbor(u);
        while (k != -1) {
            w = G.getWeight(u, k);
            pre = path[u];
            if (!S[k] && w < maxWeight && dist[u] + w < dist[k]) {   
                // 邻接顶点 k 未加入 S，且经过 u 到 k 比已知路径更短
                // 判定是否可中转
                ukFlight = findFlight(G, fls, u, k);    // u 到 k 的航班
                if (pre == -1 || (k != u && findFlight(G, fls, pre, u).isBefore(ukFlight)) ) {
                    // 刚从源点 v 出发，或者 pre 到 u 的航班时间是在从 u 到  k 的航班前面的
                    dist[k] = dist[u] + w;
                    path[k] = u;
                    // cout << G.getValue(pre) << " -> " << G.getValue(u) << " -> " << G.getValue(k) << endl;
                }
                // else cout << G.getValue(pre) << " -> " << G.getValue(u) << " -> " << G.getValue(k) <<  " 不可换乘" << endl;
            }
            k = G.nextNeighbor(u, k);
        }
    }
}


void ShortestTotalTime(MGraph<string, int>& G, int v, vector<flight>& fls, vector<int>& dist, vector<int>& path) {
    int n = G.numberOfVertices();
    int S[maxVertices];            // 最短路径标记顶点集
    int i, j, k, pre;
    int w, min;
    flight ukFlight;
    // 初始化
    for (i = 0; i < n; i++) {
        dist.push_back(G.getWeight(v, i));     // 路径长度初始化
        S[i] = 0;                   // 标记初始化
        if (i != v && dist[i] < maxWeight) {
            path.push_back(v);            // 路径数组初始化（v 的邻接顶点）
        }
        else path.push_back(-1);
    }
    S[v] = 1; dist[v] = 0;          // 到顶点 v 已找到最短路径
    // 逐个求 v 到其他顶点最短路径
    for (i = 0; i < n-1; i++) {
        min = maxWeight; 
        int u = v;                  // 初始化
        // 找不在S中具有最短路径的顶点 u
        for (j = 0; j < n; j++) {
            if (!S[j] && dist[j] < min) {
                u = j;
                min = dist[j];
            }                       
        }                           
        S[u] = 1;                   // 将 u 加入集合 S
        // if (min < maxWeight) cout <<  "到" << G.getValue(u) << "的最短路径" << min << endl;
        /* 下面的循环相比一般的 Dijkstra 算法加入了起飞时间是否允许中转的判定 */
        /* * 再相比 ShortestPath 函数，w 变成了权值加上换乘时间 * */
        // 修改经过 u 到其他顶点的路径长度
        k = G.firstNeighbor(u);
        while (k != -1) {
            pre = path[u];
            ukFlight = findFlight(G, fls, u, k);    // u 到 k 的航班
            // 权值计算改变
            if (pre == -1) {
                w = G.getWeight(u, k);
            }
            else if (findFlight(G, fls, pre, u).getIntervalWith(ukFlight) > 0) {
                w = findFlight(G, fls, pre, u).getIntervalWith(ukFlight);
            }
            else w = G.getWeight(u, k);

            if (!S[k] && w < maxWeight && dist[u] + w < dist[k]) {   
                // 邻接顶点 k 未加入 S，且经过 u 到 k 比已知路径更短
                // 判定是否可中转
                if (pre == -1 || (k != u && findFlight(G, fls, pre, u).isBefore(ukFlight)) ) {
                    // 刚从源点 v 出发，或者 pre 到 u 的航班时间是在从 u 到  k 的航班前面的
                    dist[k] = dist[u] + w;
                    path[k] = u;
                    // cout << G.getValue(pre) << " -> " << G.getValue(u) << " -> " << G.getValue(k) << endl;
                }
                // else cout << G.getValue(pre) << " -> " << G.getValue(u) << " -> " << G.getValue(k) <<  " 不可换乘" << endl;
            }
            k = G.nextNeighbor(u, k);
        }
    }
}

// 输入起点 A 和 终点 B，以"A -> B -> C, 123"的形式输出路径
void printFlightsPath(MGraph<string, int>& G, vector<int>& dist, vector<int>& path, string A, string B) {
    int i, j;       // 两个地方对应的顶点号
    i = G.getVertexPos(A); j = G.getVertexPos(B);
    vector<int> d;
    int costWeight = dist[j];
    while(j != i && j != -1) {
        d.push_back(j);
        j = path[j];
    }
    d.push_back(i);

    if (costWeight < maxWeight) {
        while(!d.empty()) {
            cout << G.getValue(d.back());
            d.pop_back();
            if (!d.empty()) {
                cout << " -> ";
            }
        }
        cout << ", " << costWeight << endl;
    }
    else {
        cout << "从 " << A << " 到 " << B << " 在一天内没有可飞行的航班方案！" << endl;
    }
}