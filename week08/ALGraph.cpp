#include "ALGraph.h"

int getVertexPos ( ALGraph& G, Type v ) {
//函数返回从顶点数据 v 取得的顶点号，若没有，则
//函数返回-1
    int i = 0;
    while ( i < G.numVertices &&
        G.VerticesList[i].data != v ) i++;	   //查顶点表
    if ( i < G.numVertices ) return i;								//找到，返回顶点号
    else return -1; 			//未找到，返回-1
}

int firstNeighbor ( ALGraph& G, int v ) {
//找顶点v的第一个邻接顶点
    if ( v != -1 ) {		//若顶点 v 存在
        EdgeNode *p = G.VerticesList[v].adj;						//取 v 边链表第一个边结点
        if ( p != NULL ) return p->dest;							//存在, 返回第一个邻接顶点
    }
    return -1;		//第一个邻接顶点不存在
}

int nextNeighbor ( ALGraph& G, int v, int w ) {
//函数返回顶点 v 的排在邻接顶点 w 后面的下一个
//邻接顶点, 如果找不到, 则函数返回-1
    if ( v != -1 ) {		//若顶点 v 存在
        EdgeNode *p = G.VerticesList[v].adj;
        while ( p != NULL && p->dest != w ) p = p->link; 
        if ( p != NULL && p->link != NULL ) 
            return p->link->dest;	//返回下一邻接顶点
    }
    return -1; 			//下一邻接顶点不存在
}

Type getValue ( ALGraph& G, int v ) {  //取顶点v数据
    if ( v != -1 ) return G.VerticesList[v].data;	
    else return impossibleValue;
}

Weight getWeight ( ALGraph& G, int v, int w ) {	
//取边(v, w)上的权值
    EdgeNode *p = G.VerticesList[v].adj;  //找边(v, w)
    while ( p != NULL && p->dest != w ) p = p->link;
    if ( p != NULL ) return p->cost;   //找到, 返回权值
    else return impossibleWeight;
}