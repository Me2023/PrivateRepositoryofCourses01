// 链式栈：栈顶在链头，插入与删除仅在栈顶处执行。
#include <stdio.h>
#include <stdlib.h>

typedef int SElemType;	        //每个栈元素的数据类型

typedef struct node {           //栈元素结点定义
     SElemType data;	        //结点数据	
     struct node *link;         //结点链接指针
} LinkNode, *LinkList, *LinkStack;      //链式栈

// 栈初始化，不需要头结点
void initStack( LinkStack& S ) {   
    S = NULL;	       //置空栈
}

// 判栈空否
bool stackEmpty( LinkStack& S ) {    
     return S == NULL;
}

// 进栈
bool Push( LinkStack& S, SElemType x ) {  
     LinkNode *p = (LinkNode *) malloc ( sizeof(LinkNode )); 	//创建新结点
     if ( p == NULL ){ printf ("结点创建失败!\n");  exit(1); }                                                  
     p->data = x;  			   //结点赋值
     p->link = S;  S = p;      //链入栈顶
     return true;
}

// 退栈
bool Pop ( LinkStack& S, SElemType& x ) {    
     if ( stackEmpty(S) ) return false;
     LinkNode * p = S; 
     x = p->data;  S = p->link; 	    //摘下原栈顶
     free (p);  return true; 	 	    //释放原栈顶结点
} 

// 看栈顶元素
bool getTop ( LinkStack& S, SElemType& x ) { 
     if ( stackEmpty (S) ) return false;
     x = S->data;  return true;
}

// 栈的混洗：出栈序列