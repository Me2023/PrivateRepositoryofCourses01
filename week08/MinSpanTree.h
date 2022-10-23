#include <stdio.h>
#define maxSize 20		//边值数组默认大小
#define maxValue 32767  	//大数
typedef int WeightType;		//权值的数据类型
typedef struct {			//最小生成树边结点
    int v1, v2;				//两顶点的顶点号
   	WeightType key;		//边上的权值
} MSTEdgeNode;
typedef struct {			//最小生成树的定义
    MSTEdgeNode edgeValue[maxSize];    //边值数组
   	int n;				//数组当前元素个数
} MinSpanTree;


void initMinSpanTree ( MinSpanTree& T ) {
//最小生成树初始化：构造一棵空树
    T.n = 0;
}

void printMinSpanTree ( MinSpanTree& T ) {
//输出最小生成树
    for ( int i = 0; i < T.n; i++ ) 
        printf ( "(%d, %d, %d) ", T.edgeValue[i].v1, 
            T.edgeValue[i].v2, T.edgeValue[i].key );
    printf ( " \n" );
}
