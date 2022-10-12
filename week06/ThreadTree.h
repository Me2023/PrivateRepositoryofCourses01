typedef  int TTElemType;

typedef struct node {
    int ltag, rtag;
    struct node *lchild, *rchild;
    TTElemType data;
} ThreadNode, *ThreadTree;
