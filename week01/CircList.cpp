#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node { // 循环链表定义
    DataType data;
    struct node *link;
} CircNode, *CircList;
// 如果插入和删除仅在链表的两端发生，可采用带表尾指针的循环链表结构。
// 除了表尾删除是O(n)，其余三个是O(1)；而如果是带头指针的循环链表，则四个操作都是O(n)

/* 在单链表中按序号查找（定位），返回表中第 i 个元素的地址，如果到了最后一个结点，
则返回最后一个结点的地址而不是NULL（区别于非循环单链表），头结点为 0 号 */
CircNode *Locate(CircList first, int i){
    if(i < 0)return NULL;
    CircNode * p = first;
    int k = 0;
    while(p->link != first && k < i){ // 找第 i 个结点，与非循环单链表条件( p != NULL && k < i )对比
        p = p->link;
        k++;
    }
    return p;
}

// 后插法建立循环单链表，数据元素链接顺序与输入顺序完全一致，并返回尾指针
CircNode *insertRear(CircList& first, DataType endTag){
    DataType val;
    CircNode *s, *rear = first; //设立尾指针rear，指向表尾，记下每次的表尾
    scanf("%d", &val);          // 读入一数据
    while(val != endTag){
        s = (CircNode *)malloc(sizeof(CircNode));
        s->data = val;          // 创建新结点并赋值
        rear->link = s;         // 插入到表尾
        rear = s;               // 尾指针指向表尾
        scanf("%d", &val);      // 读入下一数据
    }
    return rear;                // 另外，C不能返回局部变量的地址，但变量本身是指针就可以返回这个指针
}

// 在有 n 个结点的的循环单链表中从链头开始报数，每次报到第 m 个人该人出列，然后从下一个人开始继续报数
void Josephus (CircList& L, int n, int m) {
    CircNode *p = L->link, *pre = NULL; // 删除需要pre，p是报完的人和他所指向的人
    int i, j;
    for(i = 0; i < n - 1; i++) { // 执行n-1次，找到胜利者
        for(j = 1; j < m; j++) { // 报数m-1，注意p初始时已经报完第1个了
            pre = p; p = p->link; // 沿链前行
        }
        printf("出列的人是%d\n", p->data);
        pre->link=p->link; free(p); // 从链中删去
        p = pre->link; // p进到被删结点的下一结点，这个结点的人报完了数并指向下一个人
    }
    printf("最终剩下的人是%d\n", p->data);
}

