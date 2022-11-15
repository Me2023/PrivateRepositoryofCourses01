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
    // 输出图的数据
    void printMGraph(int d);
};

template<class T, class W>
MGraph<T, W>::MGraph(vector<T> v, T ed[][2], vector<W> c, int n, int e, int d) : VerticesList(v) {
    // 初始化
    this->setNumOfEdges(e);
    this->setNumOfVertices(n);
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

