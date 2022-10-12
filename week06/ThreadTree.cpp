#include "ThreadTree.h"
#include <stdio.h>

// 在中序线索二叉树中寻找第一个结点
ThreadNode * First ( ThreadNode *t ) {
//函数返回以 *t 为根的线索二叉树中的中序序列下
//的第一个结点
    ThreadNode *p = t;
    while ( p->ltag == 0 ) p = p->lchild;	
	return p; 			//最左下的结点
}

// 在中序线索二叉树中寻找指定结点的中序后继
ThreadNode * Next ( ThreadNode * p ) {
//函数返回在线索二叉树中指定结点 *p  在中序下的
//后继结点
    if ( p->rtag == 0 ) return First (p->rchild);
 		//p->rtag == 0, 后继为右子树中序第一个结点
    else  return p->rchild;
		//p->rtag == 1, 直接返回后继线索
}

void Inorder ( ThreadNode * t ) {
//以 t 为根的线索二叉树的中序遍历
     ThreadNode * p;  
     for ( p = First (t);  p != NULL;  p = Next (p) ) 
          printf ( "%d", p->data );
     printf ( "\n" );
}

// 通过中序遍历建立中序线索二叉树
void inThread (ThreadNode *t,  ThreadNode *& pre) {
 //预设了一个 pre 指针，指示 t 的中序前趋，在主
 //程序中预置为NULL
    if ( t != NULL ) {
        inThread ( t->lchild,  pre );   //对 *t 左子树线索化
        if ( t->lchild == NULL )      //对 *t 的前趋线索化
            { t->lchild = pre;  t->ltag = 1; } 
        if ( pre != NULL && pre->rchild == NULL ) 	
            { pre->rchild = t;  pre->rtag = 1; }
				     //对前趋 *pre 的后继线索化 
        pre = t;	 	    //前趋跟上,当前指针向前遍历
        inThread ( t->rchild, pre ); //对 *t 右子树线索化
	}
}
 
void createInThread ( ThreadTree T ) {
     ThreadNode *pre = NULL;  	//前趋指针
	  if ( T != NULL ) {      		//树非空, 线索化
          inThread ( T, pre );		//中序遍历线索二叉树
          pre->rchild = NULL;
          pre->rtag = 1;         //后处理, 中序最后一个结点
      }
}

// 在中序线索二叉树中寻找指定结点 *p在中序下的前趋
ThreadNode * Last ( ThreadNode *t ) {
//函数返回线索二叉树中序序列下的最后一个结点
    ThreadNode *p;
    for ( p = t; p->rtag == 0; p = p->rchild );	//最右下结点
	return p;
}
ThreadNode * Prior ( ThreadNode * p ) {
//函数返回线索二叉树中结点 *p  在中序下的前趋
    if ( p->ltag == 1 ) return p->lchild; 
    else return Last (p->lchild );
}
