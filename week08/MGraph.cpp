#include "MGraph.h"

//从顶点的数据值 x 找出该顶点的顶点号，如果查找失败，函数返回-1
int getVertexPos ( MGraph& G, Type x ) {

    for ( int i = 0; i < G.numVertices; i++ ) 
        if ( G.VerticesList[i] == x ) return i;	//找到
    return -1;		//没找到, 没有顶点号
}

//取顶点v的值
Type getValue ( MGraph& G, int v ) {					
    if ( v != -1 ) return G.VerticesList[v];
    else return impossibleValue;	     //在MGraph.h定义
}

//取边(v, w)上的权值，v、w是顶点号
Weight getWeight ( MGraph& G, int v, int w ) {
    if ( v != -1 && w != -1 ) return G.Edge[v][w];
    else return impossibleWeight;    //在MGraph.h定义
}

//函数返回顶点v的第一个邻接顶点的顶点号，如果找不到, 则函数返回-1
int firstNeighbor ( MGraph& G, int v ) {
    //在矩阵第 v 行顺序查找，一旦找到就返回。
    if ( v != -1 )
        for ( int j = 0; j < G.numVertices; j++ )
            if ( G.Edge[v][j] > 0 && 
                G.Edge[v][j] < maxWeight ) return j;
    return -1;
}

//函数返回顶点 v 的排在某邻接顶点 w 后面的下一个邻接顶点，若没有找到，则函数返回-1 
int nextNeighbor ( MGraph& G, int v, int w ) {
//从矩阵第 v 行的第 w+1 列开始顺序向后查找，找到
//即返回。
    if ( v != -1 && w != -1 )	//v, w顶点号合法
        for ( int j = w+1; j < G.numVertices; j++ ) 
            if ( G.Edge[v][j] > 0 &&
                G.Edge[v][j] < maxWeight ) return j;
    return -1;
}

