#include<stdio.h>
#include <stdlib.h>


typedef char DataType;

// 单链表的结构定义。使用时定义实际链表，只需定义链表头指针
typedef struct node { // 链表结点
    DataType data; // 结点数据域
    struct node *link; // 结点链域
} LinkNode, *LinkList; // 链头指针

// 在链表第 i (>=1) 个结点处插入新元素 x，其中表尾和表中插是一致的
bool Insert(LinkList& first, int i, DataType x) {
// 链空或插入首元的情况下，对first进行了赋值（改变了first指向的地址），故而用引用型
    LinkNode *newnode;
    newnode = (LinkNode *) malloc(sizeof(LinkNode));
    newnode->data = x;
    if(first == NULL || i == 1){ // 链空或插入首元
        newnode->link = first;
        first = newnode; // 注意先后顺序，调换则会丢掉first指向的结点
    } 
    else{
        LinkNode *p = first, *pr; int k = 1;
        while(p != NULL && k < i-1){ // 找第 i-1 个结点
            pr = p;
            p = p->link;
            k++;
        }
        if(p == NULL && first != NULL) p = pr; // 链太短，插在链尾，p收缩到链尾
        newnode->link = p->link;
        p->link = newnode;
    }
    return true;
}

/* 在链表中删除第 i 个结点。如果要删除表中第 1 个结点，需要改变头指针，
    所以first定义为引用型，被删元素的值通过引用型参数x返回。 */
bool Remove(LinkList& first, int i, DataType& x){
    LinkNode *p, *q; int k; // q 是被删结点
    if(i == 0 || first == NULL) return false; // 无效的删除位置
    if(i == 1){
        q = first; // 存储被删结点
        first = first->link;
    }
    else{ // 删除链中或链尾结点
        p = first;
        int k = 1; // 找第 i-1 个结点
        while(p != NULL && k < i-1){
            p = p->link;
            k++;
        }
        if(p == NULL || p->link == NULL){ // p->link == NULL无效？
            printf("无效的删除位置！\n");
            return false; // 链太短，没有删除结点
        }
        else{
            q = p->link; // 存储被删结点
            p->link = q->link;
        }
    }
    x = q->data; free(q); // 删除*q
    return true;
}

// 前插法建立单链表，数据元素链接顺序与输入顺序完全相反
void insertFront(LinkList& first, DataType endTag){
    DataType val;
    LinkNode *s;
    scanf("%d", &val); // 读入一数据
    while(val != endTag){ // 若不是endTag
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = val; // 创建新结点
        s->link = first->link; // 插入到表前端
        first->link = s;
        scanf("%d", &val);
    }
}

// 后插法建立单链表，数据元素链接顺序与输入顺序完全一致
void insertRear(LinkList& first, DataType endTag){
    DataType val;
    LinkNode *s, *rear = first; //设立尾指针rear，指向表尾，记下每次的表尾
    scanf("%d", &val); // 读入一数据
    while(val != endTag){
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = val; // 创建新结点并赋值
        scanf("%d", &val); // 读入下一数据
    }
}

// 单链表清空，删除链表中除表头结点外的所有其他结点
void makeEmpty(LinkList first){
    LinkNode *q; // 待删结点
    while(first->link != NULL){ // 链不空时
        q = first->link;
        first->link = q->link;
        free(q);
    }
}

// 在单链表中按值查找：在链表中从头搜索其数据值为 x 的结点，返回其地址或 NULL
LinkNode *Search(LinkList first, DataType x){
    LinkNode *p = first->link; // p 为检测指针
    while(p != NULL && p->data != x) p = p->link; // 条件不能错位，p == NULL 时 "p->data != x"是无效语句
    return p;
}

// 在单链表中按序号查找（定位），返回表中第 i 个元素的地址或 NULL ，头结点为 0 号
LinkNode *Locate(LinkList first, int i){
    if(i < 0)return NULL;
    LinkNode * p = first;
    int k = 0;
    while(p != NULL && k < i){ // 找第 i 个结点
        p = p->link;
        k++;
    }
    return p;
}

int main(){
    LinkList first; // 链表头指针
    LinkList L;
    DataType endTag;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->link = NULL; // 建立头结点并置空
    insertFront(L, endTag); //改为insertRear即为后插法
    return 0;
}
