#include "Graph.h"

/* ********邻接矩阵******** */

template<class T, class W>
int MGraph<T, W>::getVertexPos(T v) const {
    for ( int i = 0; i < this->numberOfVertices(); i++ ) 
    if ( VerticesList[i] == v ) return i;	// 找到
    return -1;		// 没找到
}

template<class T, class W>
int MGraph<T, W>::firstNeighbor(int v) const {
    //在矩阵第 v 行顺序查找，一旦找到就返回。
    if ( v != -1 ) {
        for ( int j = 0; j < this->numberOfVertices(); j++ ) {
            if ( Edge[v][j] > 0 && Edge[v][j] < maxWeight ) return j;
        }
    }
    return -1;
}

template<class T, class W>
int MGraph<T, W>::nextNeighbor (int v, int w ) const {
//从矩阵第 v 行的第 w+1 列开始顺序向后查找，找到
//即返回。
    if ( v != -1 && w != -1 )	//v, w顶点号合法
        for ( int j = w+1; j < this->numberOfVertices(); j++ ) 
            if ( Edge[v][j] > 0 &&
                Edge[v][j] < maxWeight ) return j;
    return -1;
}

template<class T, class W>
void MGraph<T, W>::printMGraph(int d) {
    int i, j, s, n, e; W w;
    n = this->numberOfVertices(); e = this->numberOfEdges();
    cout << "顶点数 = " << n << ", 边数 = " << e << endl;
    cout << "顶点数据为" << endl;
    for (i = 0; i < n; i++) cout << i << ", " << VerticesList[i] << endl;

    cout << "输出边, 形式为 (i -> j), w:" << endl;
    for (i = 0; i < n; i++) {
        s = (d == 0) ? i : 0;
        for (j = s; j < n; j++) {
            w = Edge[i][j];
            if (w > 0 && w < maxWeight) {
                cout << '(' << i << " -> " << j << "), " << w << endl;
            }
        }
    }
}
