// 利用顺序表的操作，实现以下的函数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define initSize 100 // 初始长度
typedef int DataType; // 元素的数据类型

DataType remove();  // 由于题号顺序，又避免代码重复，进行函数声明

// 测试用到的函数
// 定义顺序表
typedef struct {
    DataType *data;
    int n;
    int maxSize;
} SeqList;

// 初始化顺序表
void initList(SeqList& L){ 
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
        L.data[L.n] = val;
        L.n++;
        scanf("%d", &val); // 读入下一数据
    }
}

// 打印整数顺序表
void printList(SeqList L){
    printf("[");
    for(int i = 0; i < L.n; i++){
        printf("%d", L.data[i]);
        if(i != L.n - 1)printf(", ");
    }
    printf("]\n");
}

// 作业部分代码
/* 从顺序表中删除具有最小值的元素并由函数返回被删元素的值，
* 空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行
*/
DataType removeMin(SeqList& L){
    DataType ReturnValue;       // 函数返回变量
    // 出错情况处理
    if(L.n == 0) {printf("顺序表为空表，无法删除！\n"); exit(1);}
    // 正常运行
    // 先找最小值
    DataType min = L.data[0]; // 储存最小值
    int MinIndex = 0;           // 储存最小值的索引 
    for(int i = 1; i < L.n; i++){
        if(L.data[i] < min) min = L.data[i];
    }
    // 删除最小值元素
    for(int j = MinIndex-1; j < L.n  - 1; j++){
        L.data[j] = L.data[j+1];        // 将后面元素前移
    }
    L.n--;                              // 当前表元素个数-1
    ReturnValue = min;
    return ReturnValue;
}

/* 从顺序表中删除第i个元素并由函数返回被删元素的值
* 如果i不合理或顺序表为空则显示出错信息并退出运行 */
DataType remove(SeqList& L, int i){
    // 出错情况处理
    if(L.n == 0) {printf("顺序表为空表，无法删除！\n"); exit(1);}
    if(i <= 0 || i > L.n) {printf("i取值不合理！\n"); exit(1);}
    // 正常运行
    DataType ReturnValue = L.data[i-1];       // 被删元素的值，用于函数返回变量
    for(int j = i-1; j < L.n  - 1; j++){
        L.data[j] = L.data[j+1];        // 依次将后面元素前移
    }
    L.n--;                              // 当前表元素个数-1
    return ReturnValue;
}

/* 向顺序表中第i个位置插入一个新的元素x
* 如果i不合理则显示出错信息并退出运行 */
void insert(SeqList& L, int i, DataType x){
    // 出错情况处理
    if(i < 1 || i > L.n + 1) {printf("i取值不合理！\n"); exit(1);}
    if(L.n == L.maxSize) {printf("表溢出！\n"); exit(1);}
    // 正常运行
    for(int j = L.n-1; j>=i-1; j--) L.data[j+1] = L.data[j]; // 后续元素后移
    L.data[i-1] = x;    // 在第i个位置插入x
    L.n++;              // 元素个数+1
}

/* 从顺序表中删除具有给定值x的所有元素 */
void removeAll(SeqList& L, DataType x){
    for(int i = 0; i < L.n; i++){
        if(L.data[i] == x) remove(L, i); // 用remove函数移除给定值元素
    }
}

/* 从顺序表中删除其值在给定值s与t之间（要求s小于t）的所有元素
* 如果s或t不合理或顺序表为空则显示出错信息并退出运行 */
void removeBetween(SeqList& L, DataType s, DataType t){
    // 出错情况处理
    if(s >= t) {printf("s和t取值不合理！\n"); exit(1);}
    if(L.n == 0) {printf("顺序表为空表，无法删除！\n"); exit(1);}
    // 正确运行
    for(int i = 0; i < L.n; i++){
        if(L.data[i] > s && L.data[i] < t) remove(L, i); // 用remove函数移除满足条件的元素
    }
}

/* 从有序顺序表中删除其值在给定值s与t之间（要求s小于t）的所有元素
* 如果s或t不合理或顺序表为空则显示出错信息并退出运行 */
void removeSortedBetween(SeqList& L, DataType s, DataType t){
    // 出错情况处理
    if(s >= t) {printf("s和t取值不合理！\n"); exit(1);}
    if(L.n == 0) {printf("顺序表为空表，无法删除！\n"); exit(1);}
    // 正确运行
    /* 有序顺序表可以简化操作次数，避免remove函数多次操作移动 */
    /* 先找大于s小于t的元素部分 */

}

/* 将两个有序顺序表合并成一个新的有序顺序表并由函数返回结果顺序表 */
SeqList merge(SeqList List1, SeqList List2){
    SeqList ReturnList;
    return ReturnList;
}

/* 从顺序表中删除所有其值重复的元素，使表中所有元素的值均不相同 */
void removeRepeated(SeqList& L){

}

// 运行
int main(){
    // 建立顺序表
    SeqList TestList;
    initList(TestList);
    printf("请依次输入整数顺序表的数据, 以999作为结束\n");
    insertRear(TestList, 999);  // 以999为endTag
    printf("原顺序表为"); 
    printList(TestList);

    // 函数测试
    printf("移除了第2个元素%d\n", remove(TestList, 2));
    
    return 0;
}