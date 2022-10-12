#include <stdlib.h>
#include <stdio.h>
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
	for ( i = 0; i < n; i++ ) { 		         //逐个分支处理
        for ( j = 0; j <= k; j++ )	{         //查找双亲结点
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
    }
}

// 二叉树遍历，返回叶结点个数
int countLeaf ( BiTNode *T ) {
    if (T != NULL) {
        if (T->lchild != NULL || T->rchild != NULL) {
            return (countLeaf (T->lchild) + countLeaf (T->rchild)); // 左子树+右子树的叶结点个数
        }
        else return 1;      // 不满足上述if条件则是叶结点，故return 1
    }
    return 0;               // 空树
}

// 运行
int main() {
    char A[][3] = {{'A', 'B', '0'},  {'A', 'C', '1'},
    {'B','D', '0'},   {'B', 'E', '1'},
    {'C', 'F', '0'},  {'C', 'G', '1'},
    {'E', 'H', '0'},  {'F', 'I', '0'},
    {'F', 'J', '1'}};   // PPT上的二叉树，叶结点数为5
    BinTree BT;
    createBinTree(BT, A, 9);
    printf("%d\n", countLeaf(BT));  // 5
}