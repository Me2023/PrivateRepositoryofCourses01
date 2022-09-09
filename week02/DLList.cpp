// 循环双链表
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node{
    DataType data;
    int freq;                   // 访问计数
    struct node *lLink, *rLink; // 指针
}DblNode, *DblList;             // 双向链表

void initDblList(DblList &first){
    first = (DblNode *)malloc(sizeof(DblNode));
    if(first == NULL){
        printf("存储分配错!\n");
        exit(1);
    }
    first->lLink = first->rLink = first;
    first->freq = 0;
}

// 按值查找：在链表中从头搜索其数据值为 x 的结点，返回其地址
DblNode *Search(DblList first, DataType x, int d){
    DblNode *p = (d == 0) ? first->lLink : first->rLink;; // d == 0 则前趋查找
    while(p != first && p->data != x) p = (d == 0) ? p->lLink : p->rLink; 
    return p;
}

// 按值前趋查找：在链表中从头搜索其数据值为 x 的结点，返回其地址
DblNode *lSearch(DblList first, DataType x){
    DblNode *p = first->lLink; // p 为检测指针
    while(p != first && p->data != x) p = p->lLink; // 条件不能错位，p == NULL 时 "p->data != x"是无效语句
    return p;
}

// 按序号查找（定位），返回表中第 i 个元素的地址或 NULL
DblNode *Locate(DblList first, int i, int d){
    DblNode *p = (d == 0) ? first->lLink : first->rLink;
    for (int j=i; j<i; j++){
        if(p == first) break;
        else p = (d == 0) ? p->lLink : p->rLink; // d == 0 前趋方向，d == 1后继方向
    }
    return (p != first) ? p : NULL;
}

// 循环双链表的插入
bool Insert(DblList first, DataType x, int i, int d) {
    DblNode *p = Locate(first, i-1, d);
    if(p == NULL) return false;
    DblNode *newNode = (DblNode *)malloc(sizeof(DblNode)); // 分配结点
    newNode->data = x;
    if(d != 0){             // 在后继方向插入到*p右方
        newNode->rLink = p->rLink;      // O   o ->o
        p->rLink = newNode;             // O ->o ->o 此行与上一行不可调换顺序
        newNode->lLink = p;             // O<=>o ->o 此行与下一行可调换顺序
        newNode->rLink->lLink = newNode;// O<=>o<=>o
    }
    else{                   // 在前趋方向插入到*p左方
        newNode->lLink = p->lLink;      // o<- o   O
        p->lLink = newNode;             // o<- o<- O 此行与上一行不可调换顺序
        newNode->rLink = p;             // o<- o<=>O 此行与下一行可调换顺序
        newNode->lLink->rLink = newNode;// o<=>o<=>O
    }
    return true;
}

// 循环双链表的删除，删除在d指明方向的第i个结点，x返回其值
bool Remove(DblList first, int i, int d, DataType& x) {
    DblNode *p = Locate(first, i, d);   // 指针定位于删除结点位置
    if(p == NULL) return false;
    p->rLink->lLink = p->lLink;
    p->lLink->rLink = p->rLink;         // 将被删结点p从链上摘下
    x = p->data;
    free(p);                            // 删去
    return true;
}

int main() {

}