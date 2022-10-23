// 邻接表表示的图的定义
#include<stdio.h>
#include<stdlib.h>
#define maxVertices 30	    //图中顶点数最大值
#define maxEdges 450 	    //图中边数最大值
#define impossibleValue '#'
#define impossibleWeight -1
typedef char Type;	    //顶点数据的数据类型
typedef int Weight;	    //带权图边权数据类型

//边结点的定义
typedef struct Enode {	    
    int dest;			    //边的另一顶点的顶点号
    Weight cost;		    //边上的权值
    struct Enode *link;	    //下一条边链指针
} EdgeNode;

//顶点的定义
typedef struct Vnode {	    
    Type data;			    //顶点数据
    struct Enode *adj;	    //出边表的头指针
} VertexNode;

//图的定义
typedef struct {		    
    VertexNode VerticesList[maxVertices];   //顶点表
    int numVertices; 	    //实际顶点数
    int numEdges; 		    //实际边数
} ALGraph;


