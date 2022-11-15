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

    cout << "输出边, 形式为 (i, j), w:" << endl;
    for (i = 0; i < n; i++) {
        s = (d == 0) ? i : 0;
        for (j = s; j < n; j++) {
            w = Edge[i][j];
            if (w > 0 && w < maxWeight) {
                cout << '(' << i << ", " << j << "), " << w << endl;
            }
        }
    }
}


/* ********邻接表******** */

template<class T, class W>
int ALGraph<T, W>::getVertexPos (T v) const {
//函数返回从顶点数据 v 取得的顶点号，若没有，则
//函数返回-1
    int i = 0;
    while ( i < this->numberOfVertices() &&
        VerticesList[i].data != v ) i++;	   //查顶点表
    if ( i < this->numberOfVertices() ) return i;								//找到，返回顶点号
    else return -1; 			//未找到，返回-1
}

template<class T, class W>
int ALGraph<T, W>::firstNeighbor (int v) const {
//找顶点v的第一个邻接顶点
    if ( v != -1 ) {		//若顶点 v 存在
        EdgeNode *p = VerticesList[v].adj;						//取 v 边链表第一个边结点
        if ( p != NULL ) return p->dest;							//存在, 返回第一个邻接顶点
    }
    return -1;		//第一个邻接顶点不存在
}

template<class T, class W>
int ALGraph<T, W>::nextNeighbor (int v, int w) const {
//函数返回顶点 v 的排在邻接顶点 w 后面的下一个
//邻接顶点, 如果找不到, 则函数返回-1
    if ( v != -1 ) {		//若顶点 v 存在
        EdgeNode *p = VerticesList[v].adj;
        while ( p != NULL && p->dest != w ) p = p->link; 
        if ( p != NULL && p->link != NULL ) 
            return p->link->dest;	//返回下一邻接顶点
    }
    return -1; 			//下一邻接顶点不存在
}


template<class T, class W>
W ALGraph<T, W>::getWeight (int v, int w) const {	
//取边(v, w)上的权值
    EdgeNode *p = VerticesList[v].adj;  //找边(v, w)
    while ( p != NULL && p->dest != w ) p = p->link;
    if ( p != NULL ) return p->cost;   //找到, 返回权值
    else return impossibleWeight;
}
