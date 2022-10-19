#define leafNumber 20		   //默认权重集合大小
#define totalNumber 39		   //树结点最大个数

typedef struct {
	char data;			   //结点的值
	int weight;			   //结点的权
	int parent, lchild, rchild;	   //双亲、左、右子女
} HTNode;

typedef struct {
	HTNode elem[totalNumber];   //树存储数组
	int num, root;			   //外结点数与根
} HFTree;
