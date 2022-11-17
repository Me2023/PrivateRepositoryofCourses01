#include "Graph.cpp"

template<class T, class W>
void Dijkstra(Graph<T, W>& G, int v, vector<W>& dist, vector<T>& path) {
    int n = G.numberOfVertices();
    int S[n];
    int i, j, k;
    // 初始化
    for (i = 0; i < n; i++) {

    }
}


template<class T, class W>
void ShortestPath(Graph<T, W>& G, int v, vector<W>& dist, vector<int>& path) {
// 求顶点 v 到图 G 各顶点的最短路径，算法返回 dist[] 和 path[]
    int n = G.numberOfVertices();
    int S[maxVertices];            // 最短路径标记顶点集
    int i, j, k;
    W w, min;
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
        // 修改经过 u 到其他顶点的路径长度
        for (k = 0; k < n; k++) {
            w = G.getWeight(u, k);
            if (!S[k] && w < maxWeight && dist[u] + w < dist[k]) {
                // 邻接顶点 k 未加入 S，且经过 u 到 k 比已知路径更短
                dist[k] = dist[u] + w;
                path[k] = u;
            }
        }
    }
}

// 针对航班问题，考虑时间先后
template<class T, class W>
void DijkstraInOrder(Graph<T, W>& G, int v, vector<W>& dist, vector<int>& path) {
// 求顶点 v 到图 G 各顶点的最短路径，算法返回 dist[] 和 path[]
    int n = G.numberOfVertices();
    int S[maxVertices];            // 最短路径标记顶点集
    int i, j, k;
    W w, min;
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
            if (!S[j] && dist[j] < min ) {
                u = j;
                min = dist[j];
            }                       
        }                           
        S[u] = 1;                   // 将 u 加入集合 S
        // 修改经过 u 到其他顶点的路径长度
        for (k = 0; k < n; k++) {
            w = G.getWeight(u, k);
            if (!S[k] && w < maxWeight && dist[u] + w < dist[k]) {
                // 邻接顶点 k 未加入 S，且经过 u 到 k 比已知路径更短
                dist[k] = dist[u] + w;
                path[k] = u;
            }
        }
    }
}



template<class T, class W>
void printShortestPath(MGraph<T, W>& G, int v, vector<W>& dist, vector<int>& path) {
    cout << "从顶点" << G.getValue(v) << "到其他各顶点的最短路径为：" << endl;
    int i, j, k, n = G.numberOfVertices();
    vector<int> d;             // 用于倒序存储最短路径上的顶点
    // 逐个顶点输出从 v0 到 v1的最短路径
    for (i = 0; i < n; i++) {
        // “倒序”存储该最短路径上的顶点到 d[] 并输出
        if (i != v) {               
            // 存储部分
            j = i;                    // j 用于沿路径回溯直到源点
            while (j != v && j != -1) {
                d.push_back(j);
                j = path[j];        // path[j] j 在最短路径上的“前一顶点”
            }
            d.push_back(v);
            
            // 输出部分
            if (dist[i] < maxWeight) {
                cout << "到 " << G.getValue(i) << " 的最短路径为：";
                while(!d.empty()) {
                    cout << G.getValue(d.back()) << ' ';
                    d.pop_back();
                }
                cout << endl << "最短路径长度为：" << dist[i] << endl;
            }
            else {
                cout << "从起点到 " << G.getValue(i) << " 没有通路" << endl;
            }
            
        }
    }
}
