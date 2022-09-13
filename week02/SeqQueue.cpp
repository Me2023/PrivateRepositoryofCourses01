// 顺序队列
#include <stdio.h>
#include <stdlib.h>

#define queSize 50

typedef int QElemType;	     // 每个元素的数据类型

typedef struct {		        // 顺序队列的结构定义
    QElemType elem[queSize];    // 队列存储数组
    int rear, front;          	// 队尾与队头指针
} SeqQueue, CircQueue;

/* 循环队列的实现：为区分队空和队满，队列中总是空出一个。
队头指针进1:  front = (front+1) % queSize;
队尾指针进1:  rear = (rear+1) % queSize;
队列初始化：front = rear = 0;
队空条件：front == rear;
队满条件：(rear+1) % queSize == front  */
// 置空队列
void initQueue ( CircQueue& Q ) {       
     Q.rear = 0;  Q.front = 0;
}

// 判队空否
bool queueEmpty ( CircQueue& Q ) {   
     return Q.rear == Q.front;
}

// 判队满否
bool queueFull ( CircQueue& Q ) {       
     return (Q.rear+1) % queSize == Q.front;
}

// 在循环队列Q的队尾加入新元素 x
bool enQueue ( CircQueue& Q, QElemType x ) {
     if ( queueFull(Q) ) return false;      //队已满
     Q.elem[Q.rear] = x;			        //否则，先加
     Q.rear = (Q.rear+1) % queSize;       //队尾指针进一
     return true;
}

bool deQueue ( CircQueue& Q, QElemType& x ) {
     if ( queueEmpty(Q) ) return false;		
     x = Q.elem[Q.front];			//先取队头的值
     Q.front = (Q.front+1) % queSize;	//队头指针进一
     return true;
}

bool getFront ( CircQueue& Q, QElemType& x ) {
     if ( queueEmpty(Q) ) return false;
     x = Q.elem[Q.front];  return true;
}

