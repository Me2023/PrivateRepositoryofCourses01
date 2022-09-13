// 链式队列：链式队列采用不带头结点的单链表存储队列元素，
// 队头在链头，队尾在链尾。
#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;      //元素的数据类型

// 链式队列的结构定义
typedef struct node {	
     QElemType data;	     //队列结点数据
     struct node *link;            //结点链指针
} LinkNode;

typedef struct {		    //队列结构定义
    LinkNode *rear, *front;   //队尾与队头指针
} LinkQueue;

void initQueue ( LinkQueue& Q ) {
     Q.front = NULL;  Q.rear = NULL;  //置空队列
}

bool queueEmpty ( LinkQueue& Q ) {
      return Q.front == NULL;               //判队空否
}

bool getFront ( LinkQueue& Q, QElemType& x ) {
      if ( queueEmpty(Q) ) return false;		
      x = Q.front->data;  return true;     //读取队头元素
}

// 入队
bool enQueue ( LinkQueue& Q, QElemType x ) {
    LinkNode *s = (LinkNode *) malloc (sizeof(LinkNode));   		   //创建新队尾结点
	s->data = x;  s->link = NULL;
    if ( Q.rear == NULL ) 		   //新结点加入空队，则既是队头也是队尾
        { Q.rear = s;  Q.front = s; }
    else 		    		   //新结点成新链尾
        { Q.rear->link = s;  Q.rear = s; }
    return true;	
}

// 删去队头结点，并返回队头元素的值
bool deQueue ( LinkQueue& Q, QElemType& x ) {
     if ( queueEmpty(Q) ) return false;	//队空不能删
     LinkNode *p = Q.front;		
     x = p->data;                           	           //保存队头的值
     Q.front = p->link;   		           //新队头
 	 if ( Q.front == NULL ) Q.rear = NULL;
	        //若删除后队空，队尾指针置为空
     free (p);  return true;				
}

