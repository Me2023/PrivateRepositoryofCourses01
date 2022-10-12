#ifndef SEQSTACKCLASS_H
#define SEQSTACKCLASS_H


template<class SElemType> class SeqStack{		    //顺序栈定义
public:
     SElemType *elem;	    //栈数组
     int top, maxSize; 	    //栈顶指针及栈大小
};

/*

*/
#include "SeqStack.cpp"
#endif