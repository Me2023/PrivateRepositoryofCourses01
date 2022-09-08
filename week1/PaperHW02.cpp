// 单链表逆序问题
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node {
    DataType data;
    struct node *link;
} LinkNode, *LinkList;

// 后插法建立单链表，数据元素链接顺序与输入顺序完全一致
void insertRear(LinkList& first, DataType endTag){
    DataType val;
    LinkNode *s, *rear = first; //设立尾指针rear，指向表尾，记下每次的表尾
    scanf("%d", &val);          // 读入一数据
    while(val != endTag){
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = val;          // 创建新结点并赋值
        rear->link = s;         // 插入到表尾
        rear = s;               // 尾指针指向表尾
        scanf("%d", &val);      // 读入下一数据
    }
}

// 打印整数单链表
void printList(LinkList first){
    LinkNode * p = first; 
    printf("[");
    while(p->link != NULL){
        p = p->link;
        printf("%d", p->data);
        if(p->link != NULL) printf(", "); // 美观起见，最后一个元素后面不加逗号
    }
    printf("]\n");
}

// 返回链表的结点数
int length(LinkList first){
    LinkNode *p = first;
    int k = 0;
    while(p->link != NULL){
        p = p->link;
        k += 1;
    }
    return k;
}

// 单链表逆序，时间复杂度O(n^2)
void inverse(LinkList& first) {
    // 从尾结点开始，其link指向前一结点；再而是倒数第二个；……；
    // 到第一个结点时其link指向first，最后first->link = rear

    // 变量声明和初始化
    LinkNode *p = first, *rear = first, *pre; // pre和p分别指向前后两个相邻结点，rear是要用到的尾指针
    int n = length(first), m, i;
    for(i=0; i<n; i++)rear = rear->link; // 尾指针rear指向原本的最后一个结点，在逆序过程中不改变

    // 逆序操作
    for(m=n; m>1; m--){           
        // 此层循环第j次结束后，原第n-j到n个结点构成逆序的链表，m=n-j
        for(i=0; i<m; i++){       
            // 此层循环第k次结束后，pre指向第k-1个结点，p指向第k个结点，i=k
            pre = p;
            p = p->link;
        }         
        p->link = pre;   // 逆序操作
        // 到此为止，p指向的是第m个结点，pre指向第m-1个
        p = first;       // 为下一次循环进行初始化
    }
    pre->link = NULL;    // 最后一次循环后，m=1，pre指向第0个即头结点，进行置空
    first->link = rear;  // 头指针变更
}

// 运行
int main(){
    // 变量声明
    LinkList first;             // 链表头指针
    LinkNode *rear;             // 尾指针
    DataType endTag = 999;      // 建立链表时的endTag

    // 建立链表并打印链表
    first = (LinkNode *)malloc(sizeof(LinkNode));
    first->link = NULL;         // 建立头结点并置空
    printf("请依次输入整数链表的数据, 以999作为结束\n");
    insertRear(first, endTag);
    printf("原链表为"); 
    printList(first);           // 打印建立的链表
    
    // 逆序操作并打印链表
    inverse(first);       // 逆序操作
    printf("逆序后链表为"); 
    printList(first);

    return 0;
}