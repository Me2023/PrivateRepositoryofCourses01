#include <stdio.h>
#include <stdlib.h>
#define initSize 100 // 静态最大允许长度/动态初始长度
typedef int DataType; // 元素的数据类型

// 顺序表的静态结构定义
typedef struct {
    DataType data[initSize]; // 存储数组
    int n; // 表的长度
} staticSeqList;

// 顺序表的动态结构定义，可以扩充，新的大小计入maxSize中
typedef struct {
    DataType *data;
    int n;
    int maxSize;
} SeqList;

void InitList(SeqList& L){ 
    // C++中引用型参数&的使用，将对实际变量进行操作
    /* 可在函数体内像普通变量那样对L操作，
    可直接从实际变量得到操作结果，不必创建实际变量的副本空间 */
    // 用指针替代也可以，但单链表会有麻烦
    L.data = (DataType*)malloc(initSize * sizeof(DataType));
    if(L.data == NULL){
        printf("存储分配失败！\n"); exit(1);
    }
    L.n = 0; L.maxSize = initSize;
}

// 按值查找：在顺序表中从头查找结点值等于给定结点值x的结点 n/2
int Find(SeqList& L, DataType x){
    int i;
    for(i = 0; i < L.n; i++ ){
        if(L.data[i] == x )return i;
        return -1;
    }
}

// 插入新元素 (n+1)/2
bool Insert(SeqList& L, DataType x, int i){
    // 在表中第i(1<=i<=n+1)个位置插入新元素x
    if(L.n == L.maxSize) return false;
    if(i < 1 || i > L.n+1) return false;
    for(int j = L.n-1;j>=i-1;j--)L.data[j+1] = L.data[j];
    L.data[i-1] = x;
    L.n++;
    return true;
}

// 删除表元素 (n-1)/2
bool Remove(SeqList& L, int i, DataType& x){
    // 在表中删除第i个元素，通过x返回其值
    if(L.n > 0 && i > 0 && i <= L.n){
        x = L.data[i-1];
        for(int j = i; j < L.n; j++) L.data[j-1] = L.data[j]; // 从
        L.n--; return true;
    }
    else return false;
}

int main(){

}
