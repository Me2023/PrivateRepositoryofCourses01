#include "Graph.cpp"
#define queSize 60

template<class T, class W>
void unweighted(MGraph<T, W>& G, int v, vector<W> dist, vector<T> path) {
    int Q[queSize]; int front = 0, rear = 0;       // 设置队列并置空
    int i, w, n = G.numberOfVertices();
    // 距离数组初始化
    for (i = 0; i < n; i++) {
        dist[i] = maxVertices;
    }
    dist[v] = 0; path[v] = -1;
    Q[rear] = v; rear = (rear + 1) % queSize;       // 源点进队列

    // 当队列不空时，逐层处理
    while (rear != front) {
        v = Q[front];
        front = (front + 1) % queSize;              // v 已处理，出队
        // 对 v 的各个邻接顶点 w 进行处理
        for (w = G.firstNeighbor(v); w != -1; w = G.nextNeighbor(v, w)) {
            if (dist[w] == maxVertices) {
            // 若 w 未求得最短路径
                dist[w] = dist[v] + 1;
                path[w] = v;
                Q[rear] = w;
                rear = (rear + 1) % queSize;        // w 进队尾
            }
        }
    }
}

template<class T, class W>
void ShortestPath(MGraph<T, W>& G, int v, vector<W> dist, vector<T> path) {
// 求顶点 v 到图 G 各顶点的最短路径，算法返回 dist[] 和 path[]
    int n = G.numberOfVertices();
    int S[maxVertices];            // 最短路径标记顶点集
    int i, j, k;
    W w, min;
    // 初始化
    for (i = 0; i < n; i++) {
        dist[i] = G.Edge[v][i];     // 路径长度初始化
        S[i] = 0;                   // 标记初始化
        if (i != v && dist[i] < maxWeight) {
            path[i] = v;            // 路径数组初始化（v 的邻接顶点）
        }
        else path[i] = -1;
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
            w = G.Edge[u][k];
            if (!S[k] && w < maxWeight && dist[u] + w < dist[k]) {
                // 邻接顶点 k 未加入 S，且经过 u 到 k 比已知路径更短
                dist[k] = dist[u] + w;
                path[k] = u;
            }
        }
    }
}

template<class T, class W>
void printShortestPath(MGraph<T, W>& G, int v, vector<W> dist, vector<T> path) {
    printf("从顶点[%c]到其他各顶点的最短路径为：\n", G.VerticesList[v]);
    int i, j, k, n = numOfVertices(G);
    int d[maxVertices];             // 用于倒序存储最短路径上的顶点
    // 逐个顶点输出从 v0 到 v1的最短路径
    for (i = 0; i < n; i++) {
        // “倒序”存储该最短路径上的顶点到 d[] 并输出
        if (i != v) {               
            // 存储部分
            j = i; k = 0;           // j 用于沿路径回溯直到源点
            while (j != v) {
                d[k++] = j;
                j = path[j];        // path[j] j 在最短路径上的“前一顶点”
            }
            d[k++] = v;

            // 输出部分
            printf("到顶点[%c]的最短路径为：", G.VerticesList[i]);
            while(k > 0) {
                printf("%c ", G.VerticesList[d[--k]]);
            }
            printf("\n最短路径长度为：%d\n", dist[i]);
        }
    }
}

template<class T, class W>
void Bellman_Ford(MGraph<T, W>& G, W dist[], int path[]) {
    int i, k, u, n = G.numVertices;
    // 初始化
    for (i = 0; i < n; i++) {
        dist[i] = G.Edge[0][i];
        path[i] = (G.Edge[0][i] < maxWeight) ? 0 : -1;
    }
    // 递推求 dist[u]
    for (k = 2; k < n; k++) {
        // 终点
        for (u = 1; u < n; u++) {
            // 要绕的顶点
            for (i = 1; i < n; i++) {
                if (dist[u] > dist[i] + G.Edge[i][u])
                    {dist[u] = dist[i] + G.Edge[i][u]; path[u] = i;}
            }
        }
    }
}