#include <cstdlib>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define initSize 100
#define increment 20
#include "SeqStack.h"

// 初始化
template<typename T>
SeqStack<T>::SeqStack() {
    elem = new T[initSize];
    top = -1; 
    maxSize = initSize;
}

// 判栈空否
template<typename T>
bool SeqStack<T>::stackEmpty() {
    return top == -1;
}

// 判栈满否
template<typename T>
bool SeqStack<T>::stackFull() {
    return top == maxSize - 1;
}

// 栈满处理
template<typename T>
void SeqStack<T>::overFlow() {
    int newSize = maxSize + increment;
    T *newS;
    newS = new T[newSize];
    for(int i = 0; i <= top; i++) newS[i] = elem[i];
    delete elem;
    elem = newS;
    maxSize = newSize;
}

// 进栈
template<typename T>
void SeqStack<T>::Push(T x) {
    if (SeqStack<T>::stackFull()) overFlow();
    top++;
    elem[top] = x;
}

// 退栈
template<typename T>
T SeqStack<T>::Pop() {
    if (SeqStack<T>::stackEmpty()) exit(1);
    top--;
    return elem[top+1];
}

template<typename T>
T SeqStack<T>::getTop() {
    if (SeqStack<T>::stackEmpty()) exit(1);
    return elem[top];
}

