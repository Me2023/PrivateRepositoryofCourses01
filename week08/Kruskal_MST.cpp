#include "UFSets.h"
#include "MinSpanTree.h"
#include "minHeap.h"
#include "ALGraph.cpp"
void Kruskal_MST ( ALGraph& G, MinSpanTree& T ) {
    int i, j, k, u, v;  Edge w; 
    UFSets Uset;  Initial ( Uset );	  //建立并查集Uset
    initMinSpanTree ( T );		  //最小生成树置空
    minHeap H;  initMinHeap ( H );	//建立小根堆
    int n = numberOfVertices(G) , e = numberOfEdges(G);					 //图的顶点数和边数
    for ( i = 0; i < n; i++ ) 	    //将所有边插入小根堆
        for ( j = firstNeighbor ( G, i ); j != -1;
               j = nextNeighbor ( G, i, j ) ) {
            if ( i < j ) {
                w.v1 = i;  w.v2 = j;
                w.key = getWeight (G, w.v1, w.v2 );
                Insert ( H, w );
            }
       }
    j = 0;  k = 0;
    while ( k < e ) {		//大循环，选生成树的边
        if ( ! heapEmpty(H) ) Remove ( H, w );  
        else break; 	        //从小根堆退出一条最小边 w        
        u = Find ( Uset, w.v1 );  v = Find ( Uset, w.v2 );    
        if ( u != v ) {	        //若不在同一连通分量
            T.edgeValue[T.n].v1 = w.v1;    //加入生成树
            T.edgeValue[T.n].v2 = w.v2;
            T.edgeValue[T.n++].key = w.key;
            Merge ( Uset, u, v );  	         //合并连通分量
            j++;		      //加入生成树的边计数
        }
        k++;		      //选过的边计数
    }
    if ( j < n-1 ) 	     //若生成树的边不足
        printf ( "该图不连通，无最小生成树！\n" );
}
