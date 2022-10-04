#include "BinTree.h"
#define queSize 64
void createBinTree ( BinTree& BT, char a[ ][3], int n ) {
//从字符数组 a 中输入 n 条分支，建立二叉树 BT 的
//二叉链表，要求各分支按层输入
	int i, j, k = 0;  BiTNode *s, *p;
	BT = ( BiTNode *) malloc ( sizeof (BiTNode) );
	BT->data = a[0][0];  			//建根结点
    BT->lchild = NULL;  BT->rchild = NULL;
	BinTree Q[queSize];  Q[0] = BT;     //Q存已建结点
	for ( i = 0; i < n; i++ ) 		         //逐个分支处理
        for ( j = 0; j <= k; j++ )	         //查找双亲结点
                    if ( a[i][0] == Q[j]->data ) {	//查到双亲
                p = ( BiTNode *) malloc ( sizeof (BiTNode));
                p->data = a[i][1]; 	          //建子女结点
                p->lchild = p->rchild= NULL;
                s = Q[j];  Q[++k] = p;            //子女保存
                if ( a[i][2] == '0' ) s->lchild = p;
                else s->rchild = p;	          //链接
                break;
           }
}
