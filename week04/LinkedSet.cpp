// 基于有序链表表示集合
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *link;
}SetNode, *LinkedSet;

void initSet(LinkedSet& S) {
    S = (SetNode *) malloc(sizeof(SetNode));
    S->link = NULL;
}

// 集合的查找
SetNode *Contains(LinkedSet& S, ElemType x) {
    // 如果x是集合S的成员，则函数返回与x匹配的集合结点地址，否则函数返回NULL
    SetNode *p = S->link;
    while (p != NULL && p->data < x) p = p ->link;
    if (p != NULL && p->data == x) return p;
    else return NULL;
}

// 集合的插入
bool addMember(LinkedSet& S, ElemType x) {
    // 把新元素x加入到集合之中。若集合中已有此元素，则不插入且函数返回false，否则返回true
    SetNode *p = S->link, *pr = S;      // p是扫描指针，pr是p的前驱
    while (p != NULL && p->data < x) {
        pr = p;
        p = p->link;
    }
    if (p != NULL && p->data == x) return false;        // 集合中已有此元素，不插入
    SetNode *q = (SetNode *) malloc(sizeof(SetNode));   // 创建结点
    q->data = x; q->link = p; pr->link = q;             // 新元素链入
    return true;
}

// 集合删除元素
bool delMember(LinkedSet& S, ElemType x) {
    // 把集合中成员x删去。若集合不空且元素x在集合中，则函数返回true，否则返回false
    SetNode *p = S->link, *pr = S;
    while (p != NULL && p->data < x) {  // 循链扫描
        pr = p;
        p = p->link;
    }
    if (p != NULL && p->data == x) {    // 找到，可以删除结点p
        pr -> link = p-> link;          // 重新连接，从链上摘下结点p
        free(p);
        return true;
    }
    else return false;  // 集合中无此元素，不能删除
}