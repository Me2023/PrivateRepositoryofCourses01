#include <stdio.h>
#include <stdlib.h>
#include "SetList.h"

// 初始化
void initSet(LinkedSet& S) {
    S = (SetNode *) malloc (sizeof(SetNode));
    S->link = NULL;
}

// 尾插法建立集合
void insertRear(LinkedSet& S, DataType endTag) {
    DataType val;
    SetNode *p = S->link, *pr = S;      // p是扫描指针，pr是p的前驱
    scanf("%d", &val); // 读入一数据
    while (val != endTag) {
        while (p != NULL && p->data < val) {  // 先进行定位
            pr = p;
            p = p->link;
        }
        if (p != NULL && p->data == val) {  
            // 如果集合中已存在此元素，读入下一数据，并直接进行下一次循环
            scanf("%d", &val);
            continue;
        }
        SetNode *q = (SetNode *)
        scanf("%d", &val); // 读入下一数据
    }
}

// 查找给定元素是否在集合内
SetNode *Contains(LinkedSet& S, DataType x) {
    // 如果x是集合S的成员，则函数返回与x匹配的集合结点地址，否则函数返回NULL
    SetNode *p = S->link;
    while (p != NULL && p->data < x) p = p ->link;
    if (p != NULL && p->data == x) return p;
    else return NULL;
}

// 将新元素插入集合中
