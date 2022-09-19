// 利用顺序表的操作，实现以下的函数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define initSize 100 // 初始长度
typedef int DataType; // 元素的数据类型

// 定义顺序表
typedef struct {
    DataType *data;
    int n;
    int maxSize;
} SeqList;

// 初始化顺序表
void InitList(SeqList& L){ 
    L.data = (DataType*)malloc(initSize * sizeof(DataType));
    if(L.data == NULL){
        printf("存储分配失败！\n"); exit(1);
    }
    L.n = 0; 
    L.maxSize = initSize;
}

// 后插建立顺序表
void insertRear(SeqList& L, DataType endTag){
    DataType val;
    scanf("%d", &val); // 读入一数据
    while(val != endTag && L.n != L.maxSize){
        L.data[L.n - 1] = val;
        L.n++;
        scanf("%d", &val); // 读入下一数据
    }
}

// 打印整数顺序表
void printIntList(SeqList L){
    for(int i = 0; i < L.n; i++){

    }
}

/* 从顺序表中删除具有最小值的元素并由函数返回被删元素的值
* 空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行 */
DataType removeMin(SeqList& L){

}

/* 从顺序表中删除第i个元素并由函数返回被删元素的值
* 如果i不合理或顺序表为空则显示出错信息并退出运行 */
DataType remove(SeqList& L, int i){
    if(L.n == 0){}
    if(i <= 0 || i > L.n){ printf("i取值不合理!"); exit(1); }
    DataType value = L.data[i-1];       // 被删元素的值
    for(int j = i-1; j < L.n  - 1; j++){
        L.data[j] = L.data[j+1];        // 将后面元素前移
    }
    return value;
}

/* 向顺序表中第i个位置插入一个新的元素x
* 如果i不合理则显示出错信息并退出运行 */
void insert(SeqList& L, int i, DataType x){

}

/* 从顺序表中删除具有给定值x的所有元素 */
void removeAll(SeqList& L, DataType x){

}

/* 从顺序表中删除其值在给定值s与t之间（要求s小于t）的所有元素
* 如果s或t不合理或顺序表为空则显示出错信息并退出运行 */
void removeBetween(SeqList& L, DataType s, DataType t){

}

/* 从有序顺序表中删除其值在给定值s与t之间（要求s小于t）的所有元素
* 如果s或t不合理或顺序表为空则显示出错信息并退出运行 */
void removeSortedBetween(SeqList& L, DataType s, DataType t){

}

/* 将两个有序顺序表合并成一个新的有序顺序表并由函数返回结果顺序表 */
SeqList merge(SeqList List1, SeqList List2){

}

/* 从顺序表中删除所有其值重复的元素，使表中所有元素的值均不相同 */