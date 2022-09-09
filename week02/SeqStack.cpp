#include <stdio.h>
#include <stdlib.h>

#define initSize 100
#define increment 20

typedef int SElemType;

typedef struct {		    //顺序栈定义
     SElemType *elem;	    //栈数组
     int top, maxSize; 	    //栈顶指针及栈大小
} SeqStack;

//初始化
void initStack ( SeqStack& S ) {            
    S.elem = (SElemType *) malloc ( initSize*
            sizeof ( SElemType ));
    if (S.elem == NULL) 
          { printf ("存储分配失败!\n");  exit(1); }
     S.top = -1;  S.maxSize = initSize; 
}

//判断栈是否空？空则返回true，否则返回false
bool stackEmpty (SeqStack& S) {
     return S.top == -1;
}

bool stackFull ( SeqStack& S ) {
//判断栈是否满？满则返回true，否则返回false
    return S.top == S.maxSize-1; 
}

void Push ( SeqStack& S, SElemType x ) {
//若栈不满则新元素 x 进栈，否则扩大空间再进栈 
    if ( stackFull(S) ) overFlow(S);   //栈满溢出处理
    S.top++;
    S.elem[S.top] = x;                       //加入新元素
}

void overFlow(SeqStack& S) {   //栈满处理
    int newSize = S.maxSize + increment; 
    SElemType *newS = (SElemType *) malloc (newSize*
          sizeof (SElemType ));	//创建新数组
    for ( int i = 0; i <= S.top; i++ )
            newS[i] = S.elem[i];   	//向新数组传送数据
    free (S.elem);             	          //释放老数组
    S.elem = newS;              	//新数组作为栈数组
    S.maxSize = newSize; 	          //新数组大小
}                                          	//栈顶指针不变

bool Pop ( SeqStack& S, SElemType& x ) {
//若栈空返回false, 否则栈顶元素退出到x并返回true
     if ( stackEmpty(S) ) return false;    //栈空返回false
     x = S.elem[S.top];  S.top--;            //否则先取再退
     return true;			          //返回true
}

bool getTop ( SeqStack& S, SElemType& x ) {
//若栈空返回false, 否则栈顶元素读到x并返回true
     if ( stackEmpty(S) ) return false;    //栈空返回false
     x = S.elem[S.top];		          //否则读栈顶
     return true;			          //返回true
}
