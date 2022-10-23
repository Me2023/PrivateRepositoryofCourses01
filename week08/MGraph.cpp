#include "MGraph.h"

//从顶点的数据值 x 找出该顶点的顶点号，如果查找失败，函数返回-1
int getVertexPos ( MGraph& G, Type x ) {

    for ( int i = 0; i < G.numVertices; i++ ) 
        if ( G.VerticesList[i] == x ) return i;	//找到
    return -1;		//没找到, 没有顶点号
}

int numberOfVertices (MGraph& G) {
    return 0;
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

// 图的深度优先搜索算法DFS ( Depth First Search )
void DFS_Traversal ( MGraph& G, int v ) {
//从顶点 v 出发，对图G进行深度优先遍历的主过程
    int i, n = numberOfVertices ( G ); 	//取图中顶点数
    int visited[maxVertices];		//访问标记数组
    for ( i = 0; i < n; i++ ) visited[i] = 0;
	DFS_recur ( G, v, visited );
	printf ( "\n" );
}

void DFS_recur ( MGraph& G, int v, int visited[ ] ) {
//从顶点 v 出发, 以深度优先次序访问所有尚未访问
//过的顶点。算法中用到一个辅助数组 visited, 对已
//访问过的顶点作访问标记
    printf ( "%c ", getValue(G, v) ); //访问顶点 v
    visited[v] = 1;			     //作访问标记
    int w = firstNeighbor ( G, v );	     //递归遍历邻接顶点
    while ( w != -1 ) {		
        if ( ! visited[w] ) DFS_recur ( G, w, visited );
        w = nextNeighbor ( G, v, w ) ;
	}
}



/*
求连通分量的算法需要对图的每一个顶点进行检测：
若已被访问过，则该顶点一定是落在图中已求得的连通分量上；若还未被访问，则从该顶点出发遍历图，可求得图的另一个连通分量。
*/
// 深度优先搜索求连通分量
void calcComponents ( MGraph& G ) {
    int i, k, n = numberOfVertices (G); 	// 图顶点个数
    int *visited = (int*) malloc ( n*sizeof (int));
    for ( i = 0; i < n; i++ ) visited[i] = 0;
    k = 0;			    // 连通分量计数
    for ( i = 0; i < n; i++ )  	    // 顺序扫描所有顶点
        if ( ! visited[i] ) {	    // 若未访问过, 访问
            printf ( "输出第%d个连通分量的边: \n", ++k );
            DFS_recur ( G, i, visited );  //遍历一个连通分量
	        printf ( "\n" );
        }
    free ( visited );
}
// 广度优先亦可

/* 克鲁斯卡尔 (Kruskal) 算法：用到并叉集UFSets和最小堆
将 E 中所有的边按权值存放在小根堆中，每次选择权值最小的边出堆

*/