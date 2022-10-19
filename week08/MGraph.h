// 用邻接矩阵表示的图结构的定义
#include <stdio.h>
#include <stdlib.h>
#define maxVertices 30		//图中顶点数最大值
#define maxEdges 900		//最大边数
#define maxWeight 32767	//最大权值
#define impossibleValue '#'
#define impossibleWeight -1

typedef char Type;	//顶点数据的数据类型
typedef int Weight;	//带权图中边权值数据类型
typedef struct {
	int numVertices;		//图中实际顶点数	
	int numEdges; 		//图中实际边数
    Type VerticesList [maxVertices]; 		//顶点表
   	Weight Edge[maxVertices][maxVertices];	//邻接矩阵
} MGraph;
