#include "MinSpanTree.h"
#include "minHeap.h"
#include "MGraph.cpp"
void Prim ( MGraph& G, int u0, MinSpanTree& T ) {
//从带权连通图G的顶点u0出发，构造最小生成树T
	Edge w;  int i, u, v, count;
	int n = numberOfVertices(G);	    //顶点数
	int e = numberOfEdges(G);	    //边数
	minHeap H;  initMinHeap(H);    //小根堆
	bool *Vmst = (bool *) malloc ( n*sizeof ( bool ));	
					//最小生成树顶点集合	
	for ( i = 0; i < n; i++ ) Vmst[i] = false;
    Vmst[u0] = true;  u = u0;	//u0加入生成树
    count = 1;  T.n = -1;
	do {		//迭代, 逐条边加入生成树
        v = firstNeighbor ( G, u );	//取 u第一个邻接顶点
        while ( v != -1 ) {		//当邻接顶点存在
            if ( !Vmst[v] ) {	    //若 v 不在生成树, 加入堆
                w.v1 = u;  w.v2 = v;
                w.key = getWeight ( G, u, v );		              
                Insert ( H, w );
	        }
            v = nextNeighbor(G, u, v) );  //下一个邻接顶点
	    }
        while ( ! heapEmpty(H) && count < n ) { 
            Remove ( H, w );	//从堆中退出具最小权重的边
	        printf ( "(%d, %d, %d)\n", w.v1, w.v2, w.key );
            if ( ! Vmst[w.v2] ) { 	//若不会构成回路, 则
                T.edgeValue[++T.n].v1 = w.v1;    //加入最小 
                T.edgeValue[T.n].v2 = w.v2;        //生成树
	            T.edgeValue[T.n].key = w.key;		
                u = w.v2;  Vmst[u] = true;	       //u加入Vmst
                count++;  break;
	       }
	   }
    } while ( count < n );
}
