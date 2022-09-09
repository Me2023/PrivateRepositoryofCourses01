// 静态链表
#include <stdio.h>
#include <stdlib.h>
#define maxSize 100        // 静态链表大小

typedef int DataType;

typedef struct {
    DataType data;         // 节点数据
    int link;              // 结点链接指针
} SLNode;  

typedef struct {
    SLNode elem[maxSize+1];
	int avail;			//当前可分配空间首地址
} StaticLinkList;  

//将链表空间初始化
void InitList ( StaticLinkList& A ) {
    A.elem[0].link = -1;   
    A.avail = 1;	                //当前可分配空间从 1 开始
    for ( int i = 1; i < maxSize-1; i++ )
        A.elem[i].link = i+1;       //构成空闲链接表
    A.elem[maxSize-1].link = -1;    //链表收尾
};

int Length ( StaticLinkList& A ) {
    //计算静态链表的长度
        int p = A.elem[0].link;  int count = 0;
        while ( p != -1 ) {
            p = A.elem[p].link;  count++;
        }
        return count;
    };

bool IsEmpty ( StaticLinkList& A ) {
//判链表空否？
    return ( A.elem[0].link == -1);
};

int Search ( StaticLinkList& A, DataType x ) {
//在静态链表中查找具有给定值的结点
    int p = A.elem[0].link;    //指针 p 指向表的首元素
    while ( p != -1 ) 	      //逐个结点检测
            if ( A.elem[p].data == x ) break;
            else p = A.elem[p].link;
    return p;
};

int Locate ( StaticLinkList& A, int i ) {
//在静态链表中查找第 i 个结点
    if ( i < 0 ) return -1;        	//参数不合理
    if ( i == 0 ) return 0;
    int j = 1,  p = A.elem[0].link; 
    while ( p != -1 && j < i )
            { p = A.elem[p].link;  j++; }
                //循链查找第 i 号结点
    return p;
};

int AllocNode ( StaticLinkList& A ) {
//从可利用空间表分配一个可利用结点
    if ( A.avail == -1 ) return -1;
    int q = A.avail;                  	//分配结点
    A.avail = A.elem[A.avail].link;
    return q;
};

void FreeNode ( StaticLinkList& A, int i ) {
//将结点 i 回收到可利用空间表
    A.elem[i].link = A.avail;
    A.avail = i;
};

bool InsertFront ( StaticLinkList& A, DataType x ) {
//在静态链表的表头插入一个新结点
    int p = AllocNode (A);
    if ( p == -1 ) return false;     //结点分配失败
    A.elem[p].data = x;
    A.elem[p].link = A.elem[0].link;		
    A.elem[0].link = p;                //在链头链入结点
    return true;		
}; 

bool Insert ( StaticLinkList& A, int i, DataType x ) {
//在静态链表A第 i 个结点后面插入新结点
    int p = Locate(A, i); 
    if ( p == -1 ) return false; 	    //找不到结点
    int q = AllocNode (A);	    //分配结点
    if ( q == -1 ) return false;      //分配结点失败
    A.elem[q].data = x;
    A.elem[q].link = A.elem[p].link;   //链入
    A.elem[p].link = q;
    return true;
};

bool Remove ( StaticLinkList& A, int i, DataType& x ) {
//在静态链表A中释放第 i 个结点, 通过 x 返回其值
    int p = Locate(A, i-1);     	     //找第i-1号结点
    if ( p == -1 ) return false;       //找不到结点
    if ( A.elem[p].link == -1 ) return false;
    int q = A.elem[p].link;              //第i号结点
    x = A.elem[q].data;
    A.elem[p].link = A.elem[q].link;  //摘下第i号结点
    FreeNode (A, q);        	    //释放
    return true;
};

