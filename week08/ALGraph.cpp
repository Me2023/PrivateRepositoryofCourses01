#include "ALGraph.h"

int numberOfVertices (ALGraph& G) {
    return 0;
}

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

// 图的广度优先搜索算法
void BFS_Traversal ( ALGraph& G ) {
//算法实现图 G 的广度优先搜索。其中使用了一个队
//列Q，队头和队尾指针分别为front和rear
	int i, j, w, n = numberOfVertices(G);
	int visited[maxVertices];	                // 访问标志数组
	for ( i = 0 ; i < n; i++ ) visited[i] = 0;
	int Q[maxVertices];  int front = 0; int rear = 0;  // 队列置空
	for ( i = 0 ; i < n; i++ )		            // 顺序扫描所有顶点（包括非连通）
        if ( ! visited[i] ) {		            
            // 若顶点 i 未访问过
            printf ( "%c ", getValue(G, i) );	// 访问 
            visited[i] = 1;  Q[rear++] = i;	    // 进队列
            // 开始对这个连通分量的广度优先搜索
            while ( front < rear ) {	        // 队列不空时执行
                j = Q[front++];		            // 队头 j 出队
                w = firstNeighbor ( G, j );
                while ( w != -1 ) {	            // 若邻接顶点w存在
                    if ( ! visited[w] ) {	    // 且该顶点未访问过
                        printf ( "%c ", getValue(G, w) );    //访问
                        visited[w] = 1;  Q[rear++] = w;      //进队
                    }
                    w = nextNeighbor ( G, j, w ) ;		
                }
            }
        }
}
