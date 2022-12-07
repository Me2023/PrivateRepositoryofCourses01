// 二叉查找树
#include <stdio.h>
#include <stdlib.h>

typedef int TElemType; //结点关键码数据类型

typedef struct tnode {
    TElemType data; //结点值
    struct tnode *lchild, *rchild; //左、右子女指针
} BSTNode, *BSTree;


BSTNode *searchIter ( BSTree BT, TElemType x, BSTNode *& pr ) {
// 在二叉查找树 BT 中查找关键码等于 x 的结点，成功时函数返回找到结点地址，pr 是其双亲结点
// 不成功时函数返回空，pr 返回最后走到的结点地址
	BSTNode *p = BT;  pr = NULL;
	while ( p != NULL && p->data != x ) {
        pr = p;				//向下层继续查找
	    if ( x < p->data ) p = p->lchild;
  	    else p = p->rchild;
	}	
    return p;
} 

bool insert ( BSTree& t, TElemType x ) {
// 向根为 *t 的二叉查找树插入一个关键码为 x 的结点
	BSTNode *s, *p, *f;
	p = searchIter ( t, x, f ); 	        // 寻找插入位置
	if ( p != NULL ) return false;	        // 查找成功,  不插入
    
	s = ( BSTNode * ) malloc ( sizeof ( BSTNode ) );	
    s->data = x;  s->lchild = s->rchild = NULL;
	if ( t == NULL ) t = s; 	            // 原为空树，结点为根结点
	else if ( x < f->data ) f->lchild = s;  // 按左子女插入
	else f->rchild = s; 		            // 按右子女插入
	return true;
}
