#include <stdio.h>
#include <stdlib.h>
#include "SetList.h"

// 初始化，有头节点
void initSet(LinkedSet& S) {
    S = (SetNode *) malloc (sizeof(SetNode));
    S->link = NULL;
}
// 测试用到的函数
// 从数组A[n]建立集合，返回至S，S应是空集合
void createSet(LinkedSet& S, DataType A[], int n) {
    for (int i = 0; i < n; i++) {
        addMember(S, A[i]);
    }
}

// 作业部分代码
/* 尾插法建立集合 */
void insertRear(LinkedSet& S, DataType endTag) {
    DataType val;
    SetNode *p = S, *pr = S;          // p是扫描指针，pr是p的前驱
    scanf("%d", &val); // 读入一数据
    while (val != endTag) {
        while (p != NULL && p->data < val) { // 先进行定位查找
            pr = p;
            p = p->link;
        }
        if (p != NULL && p->data == val) {  
            // 如果集合中已存在此元素，读入下一数据，并直接进行下一次循环
            p = S, pr = S;
            scanf("%d", &val);
            continue;
        }
        SetNode *q = (SetNode *) malloc (sizeof(SetNode));
        q->data = val; q->link = p; pr->link = q;   // 新元素链入
        p = S, pr = S;
        scanf("%d", &val);          // 读入下一数据
    }
}

/* 查找给定元素是否在集合内 */
SetNode *Contains(LinkedSet& S, DataType x) {
    // 如果x是集合S的成员，则函数返回与x匹配的集合结点地址，否则函数返回NULL
    SetNode *p = S;
    while (p != NULL && p->data < x) p = p->link;
    if (p->data == x) return p;
    else return NULL;
}

/* 将新元素插入集合中 */
bool addMember(LinkedSet& S, DataType x) {
    // 把新元素x加入到集合之中。若集合中已有此元素，则不插入且函数返回false，否则返回true
    SetNode *p = S->link, *pr = S;
    while (p != NULL && p->data < x) {
        pr = p;
        p = p->link;
    }
    if (p != NULL && p->data == x) return false;
    SetNode *q = (SetNode *) malloc (sizeof(SetNode));
    q->data = x;
    q->link = p;
    pr->link = q;
    return true;
}

/* 删除指定元素 */
bool delMember(LinkedSet& S, DataType x) {
    // 把集合中成员x删去。若集合不空且元素x在集合中，则函数返回true，否则返回false
    SetNode *p = S, *pr =  S;
    while (p != NULL && p->data < x) {
        pr = p;
        p = p->link;
    }
    if (p != NULL && p->data == x) {    // 先判断p是否为空防止报错
        pr->link = p->link;
        free(p);
        return true;
    }
    return false;
}

/* 集合的并集 */
void Merge(LinkedSet& LA, LinkedSet& LB, LinkedSet& LC) {
    // 求集合LA和LB的并，结果通过LC返回，要求LC已存在且为空
    // 对LA和LB依次进行扫描，依次将较小的元素摘取至LC中
    SetNode *pa = LA->link, *pb = LB->link; // 分别是LA和LB的扫描指针
    while (pa != NULL || pb != NULL) {
        // 事实上if和else if的条件应该互为补集，else if可写为else，但为清晰起见还是写明
        if (pa != NULL && (pb == NULL || pa->data < pb->data)) {
            // LA没被扫描完，且“LA的扫描元素小于LB的扫描元素或LB已经被扫描完”
            addMember(LC, pa->data);    // 将此时LA的扫描元素插入LC
            pa = pa->link;              // LA继续扫描下一元素
        }
        else if (pb != NULL && (pb->data <= pa->data || pa == NULL)) {
            addMember(LC, pb->data);    // addMember已经考虑了数据相等时不插入的情况
            pb = pb->link;              // LB继续扫描下一元素
        }
    }
}

/* 集合的交集 */
void Intersect(LinkedSet& LA, LinkedSet& LB, LinkedSet& LC) {
    // 求集合LA和LB的交集，结果通过LC返回，要求LC已存在且为空
    // 对LA依次进行扫描，每扫描到一个元素，将之数据与LB的每个元素对比
    SetNode *pa = LA->link, *pb = LB->link; // 分别是LA和LB的扫描指针
    while (pa != NULL) {
        while (pb != NULL) {
            // 扫描LB，将LB中与LA此时扫描元素相同的元素插入到LC
            if (pa->data == pb->data) addMember(LC, pb->data);
            pb = pb->link;
        }
        pa = pa->link;  // LA继续扫描下一元素
        pb = LB;        // pb初始化
    }
}

/* 集合的差集 */
void Diff(LinkedSet& LA, LinkedSet& LB, LinkedSet& LC) {
    // 求集合LA和LB的差集，结果通过LC返回，要求LC已存在且为空
    // 对LA依次进行扫描，每扫描到一个元素，将之数据与LB的每个元素对比
    SetNode *pa = LA->link, *pb = LB->link; // 分别是LA和LB的扫描指针
    while (pa != NULL) {
        while (pb != NULL) {
            // 扫描LB，如果LB中有与LA此时扫描元素相同的元素，则退出循环
            if (pa->data == pb->data) break;
            pb = pb->link;      // 在break之后，全部都不相同才会最终到NULL
        }
        if (pb == NULL) addMember(LC, pa->data); // 都不相同，将该LA元素插入LC
        pa = pa->link;  // LA继续扫描下一元素
        pb = LB;        // pb初始化
    }
}

/* 输出集合 */
void printSet(LinkedSet S) {
    SetNode *p = S->link;     // 扫描指针，从首元节点（非头节点）开始打印
    printf("(");
    while (p != NULL) {
        printf("%d",p->data);
        if (p->link != NULL) printf(", ");
        p = p->link;
    }
    printf(")\n");
}


// 运行
int main() {
    // initSet, insertRear, printSet的测试
    LinkedSet S, TS1, TS2, Result;
    initSet(S); initSet(TS1); initSet(TS2); initSet(Result);
    /* printf("请依次输入集合元素\n"); insertRear(S, 999);
    printf("此集合为"); printSet(S);
    addMember(S, 2); printSet(S); */

    DataType A[10] = {9, 4, 5, 8, 7, 2, 7, 1, 11, -2};
    DataType B[10] = {-1, -2, 9, 1, 3, 6, 7, 5, 10, -2};
    createSet(TS1, A, 10); printf("TS1 = "); printSet(TS1);
    // (-2, 1, 2, 4, 5, 7, 8, 9, 11)
    createSet(TS2, B, 10); printf("TS2 = "); printSet(TS2);
    // (-2, -1, 1, 3, 5, 6, 7, 9, 10)

    printf("· 属于、增加和删除元素测试\n");
    printf("%d是TS1集合中的元素\n", Contains(TS1, 2)->data);
    addMember(TS1, 100); printf("TS1 = TS1 + {100} = "); printSet(TS1);
    // (-2, 1, 2, 4, 5, 7, 8, 9, 11, 100)
    delMember(TS2, 5); printf("TS2 = TS2 - {5} = "); printSet(TS2);
    // (-2, -1, 1, 3, 6, 7, 9, 10)
    
    printf("\n· 并、交、差集测试\n");
    Merge(TS1, TS2, Result); printf("TS1 + TS2 = "); printSet(Result);
    // (-2, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 100)
    free(Result); initSet(Result);

    Intersect(TS1, TS2, Result); printf("TS1 ^ TS2 = "); printSet(Result);
    // (-2, 1, 7, 9)
    free(Result); initSet(Result);

    Diff(TS1, TS2, Result); printf("TS1 - TS2 = "); printSet(Result);
    // (2, 4, 5, 8, 11, 100)
    free(Result);
}
