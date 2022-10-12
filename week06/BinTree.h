typedef char TElemType;  	   //树结点数据类型

typedef struct node {         	   //树结点定义
    TElemType data;              	   //结点数据
    struct node *lchild, *rchild;   //左、右子女指针
} BiTNode, *BinTree;		   //树定义
