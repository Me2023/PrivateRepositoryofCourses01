typedef int TElemType; //结点关键码数据类型

typedef struct tnode {
    TElemType data; //结点值
    struct tnode *lchild, *rchild; //左、右子女指针
} BSTNode, *BSTree;