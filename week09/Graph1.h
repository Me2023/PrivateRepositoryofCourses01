#include <vector>
#define impossibleValue '#'
#define impossibleWeight -1
#define maxVertices 30		//图中顶点数最大值
#define maxEdges 900		//最大边数
#define maxWeight 32767	//最大权值
using namespace std;

template<class T, class W>
class Graph {
private:
    int _numVertices;           // 实际顶点数
    int _numEdges;              // 实际边数
    
public:
    int numberOfVertices() const {
        return _numVertices;
    }
    int numberOfEdges() const {
        return _numEdges;
    }
    virtual int getVertexPos(T v) const = 0;      // 由数据值 v 找顶点号
    virtual T getValue(int v) const = 0;          // 取顶点 v 的值
    virtual W getWeight(int v, int w) const = 0;  // 取边 (v, w) 上的权值
    virtual int firstNeighbor(int v) const = 0;           // 返回顶点 v 的第一个邻接顶点的顶点号或 -1
    virtual int nextNeighbor(int v, int w) const = 0;     // 返回顶点 v 的排在某邻接顶点 w 后面的下一个邻接顶点或 -1
    void setNumOfVertices(int n) {
        _numVertices = n;
    }
    void setNumOfEdges(int n) {
        _numEdges = n;
    }
};

// 邻接矩阵表示的图
template<class T, class W>
class MGraph : public Graph<T, W> {
private:
    vector<T> VerticesList;                 // 顶点表
    W Edge[maxVertices][maxVertices];  // 邻接矩阵
public:
    // 构造函数
    MGraph(vector<T> v, T ed[][2], vector<W> c, int n, int e, int d);

    int getVertexPos(T v) const;
    T getValue(int v) const {
        if (v != -1) return VerticesList[v];
        else return impossibleValue;
    }      
    W getWeight(int v, int w) const {
        if ( v != -1 && w != -1 ) return Edge[v][w];
        else return impossibleWeight;
    }; 
    int firstNeighbor(int v) const;           
    int nextNeighbor(int v, int w) const; 
    
    void printMGraph(int d);
};

template<class T, class W>
MGraph<T, W>::MGraph(vector<T> v, T ed[][2], vector<W> c, int n, int e, int d) : VerticesList(v) {
    // 初始化
    setNumOfEdges(e);
    setNumOfVertices(n);
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            Edge[i][j] = (i == j) ? 0 : maxWeight;
        }
    }
    // 建立邻接矩阵
    for (k = 0; k < e; k++) {
        i = getVertexPos(ed[k][0]);
        j = getVertexPos(ed[k][1]);
        Edge[i][j] = c[k];
        if (d == 0) {
            Edge[j][i] = c[k];  // 无向图，对称元素
        }
    }
};

template<class T, class W>
int MGraph<T, W>::getVertexPos(T v) const {
    for ( int i = 0; i < numberOfVertices(); i++ ) 
    if ( VerticesList[i] == v ) return i;	// 找到
    return -1;		// 没找到
}

template<class T, class W>
int MGraph<T, W>::firstNeighbor(int v) const {
    //在矩阵第 v 行顺序查找，一旦找到就返回。
    if ( v != -1 ) {
        for ( int j = 0; j < numberOfVertices(); j++ ) {
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
        for ( int j = w+1; j < numberOfVertices(); j++ ) 
            if ( Edge[v][j] > 0 &&
                Edge[v][j] < maxWeight ) return j;
    return -1;
}

template<class T, class W>
void MGraph<T, W>::printMGraph(int d) {
    int i, j, s, n, e; W w;
    n = numberOfVertices(); e = numberOfEdges();
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


// 邻接表表示的图
template<class T, class W>
class ALGraph : public Graph<T, W> {

    // 边结点的定义
    struct EdgeNode {
        int dest;       // 边的另一顶点的顶点号
        W cost;         // 边上的权值
        EdgeNode *link;    // 下一条边链指针
    };

    struct VertexNode {
        T data;
        EdgeNode *adj;
    };

private:
    vector<VertexNode> VerticesList;                 // 顶点表

public:
    int getVertexPos(T v) const;
    T getValue(int v) const {
        if (v != -1) return VerticesList[v].data;
        else return impossibleValue;
    }
    W getWeight(int v, int w) const;
    int firstNeighbor(int v) const;           
    int nextNeighbor(int v, int w) const; 
    
};

template<class T, class W>
int ALGraph<T, W>::getVertexPos (T v) const {
//函数返回从顶点数据 v 取得的顶点号，若没有，则
//函数返回-1
    int i = 0;
    while ( i < numberOfVertices() &&
        VerticesList[i].data != v ) i++;	   //查顶点表
    if ( i < numberOfVertices() ) return i;								//找到，返回顶点号
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
