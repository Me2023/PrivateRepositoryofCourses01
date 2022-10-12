#include <stdlib.h>
#include <stdio.h>
#include "BinTree.h"

void visit ( TElemType data ) {
}

void visit1 (BiTNode *T) {
}

void InOrder ( BiTNode *T ) {
     if ( T != NULL ) {
          InOrder ( T->lchild );
          visit ( T->data );
          InOrder ( T->rchild );
     }
}

void PreOrder (BiTNode *T) {
     if (T != NULL) {
          visit (T->data);
          PreOrder (T->lchild);
          PreOrder (T->rchild);
     }
}

void PostOrder (BiTNode *T) {
     if (T != NULL) {
          PostOrder (T->lchild);
          PostOrder (T->rchild);
          visit (T->data);
     }
}

int Exchange ( BiTNode *t ) {
    if ( t != NULL && ( t->lchild != NULL ||
	        t->rchild != NULL ) ) {
	    BiTNode *s = t->lchild;  t->lchild = t->rchild;
        t->rchild = s;			//交换*t的两个子女
        Exchange ( t->lchild );       //交换左子树的子女
        Exchange ( t->rchild );	//交换右子树的子女
    }
}

// 求二叉树高度的递归算法
int  Height ( BiTNode *t ) {
     if ( t == NULL ) return 0;
     else {
         int m = Height ( t->lchild );
         int n = Height ( t->rchild ); 
         return (m > n) ? m+1 : n+1; 
     }                            
}

// 利用二叉树先序遍历序列建立二叉树 
void createBinTree_Pre ( BiTNode *& T, TElemType pre[ ], int& n ) {
     // 以递归方式建立二叉树 T，pre[ ]是输入序列，
     // 以‘;’结束，空结点的标识为‘#’。引用参数 n 初
     // 始调用前赋值0，退出后 n 是输入统计
     TElemType ch = pre[n++];  //读入结点数据
     if ( ch == ';' ) return;	//处理结束，返回
     if ( ch != '#' ) {		//建立非空子树
          T = (BiTNode *) malloc (sizeof (BiTNode));	
          T->data = ch;		//建立根结点
          createBinTree_Pre ( T->lchild, pre, n );						//递归建立左子树
          createBinTree_Pre ( T->rchild, pre, n );						//递归建立右子树
     }
     else T = NULL;		//否则建立空子树
}

// 用括号方式输出二叉树
void printBinTree ( BiTNode *t ) {
    if ( t != NULL ) {
        printf ( "%c", t->data );	  //输出根
        if ( t->lchild != NULL || t->rchild != NULL ) {
		  printf ( "(" );		         //输出左括号
		  printBinTree ( t->lchild );       //递归输出左子树
		  printf ( ", ");		         //输出逗号
		  printBinTree ( t->rchild );      //递归输出右子树
		  printf ( ") ");		        //输出右括号
        }
    }
    else printf ("  ");		  //空树，输出空格
}

// 二叉树遍历的非递归算法：欧拉巡回遍历
void eulerTour (BinTree T, BiTNode *v) {
     visit1 (v);	//“先序”
     if ( v->lchild != NULL ) 
          eulerTour (T, v->lchild);
     visit1 (v);	//“中序”
     if ( v->rchild != NULL )
          eulerTour (T, v->rchild);
     visit1 (v);	//“后序”
} 

// 利用栈实现二叉树BT的先序遍历（递归->非递归）
#define stackSize 30
void preOrder_iter ( BinTree BT ) {
// 栈中存右子树；左进为空结束递归；
// 退出后访问结点；当前结点和栈都为空时结束遍历
	BiTNode *S[stackSize];  int top = -1;  //建栈
	BiTNode *p = BT; 
 	do {
        while ( p != NULL ) {
            printf ( "%c ", p->data );	    //访问结点
            if ( p->rchild != NULL ) S[++top] = p->rchild; // 右子树进栈
            p = p->lchild; 			    //"左下"
        }
        if ( top != -1 ) p = S[top--];	    //左子树为空，"左上右下"，访问栈顶
     } while ( p != NULL || top != -1 );    // 当前结点和栈都为空时结束遍历
}

// 利用栈的中序遍历的非递归算法
void inOrder_iter ( BinTree BT ) {
// 栈中存当前结点；左进为空结束递归；
// 退出后访问结点并右进；当前结点和栈都为空时结束遍历
	BiTNode *S[stackSize];  int top = -1;
	BiTNode *p = BT;    //p是遍历指针，从根开始
	do {
          while ( p != NULL ) {   //遍历指针进到左子女
               S[++top] = p;  
               p = p->lchild;      
          }
          if ( top != -1 ) { 	  //左子树为空了，栈不空时退栈
               p = S[top--]; 	  //退栈, 访问
               printf ( "%c ", p->data );
               p = p->rchild;	//遍历指针进到右子女结点 
          }
	} while ( p != NULL || top != -1 );
}
// 入栈序列：前序序列，退栈序列：中序序列


// 利用栈的后序遍历的非递归算法
void postOrder_iter ( BinTree BT ) {
// 栈中存当前结点；左进为空结束递归；
// 退栈：右子树回来则退栈访问，左子树；当前结点和栈都为空时结束遍历
	BiTNode *S[stackSize];  int top = -1; 
	BiTNode *p = BT, *pre = NULL;	          //pre是p前趋
	do {
	    while ( p != NULL ) {			//左子树进栈
               S[++top] = p;  
               p = p->lchild;
          }
          if ( top != -1 ) {        //左子树为空了，先不退栈
               p = S[top];		    //用p记忆栈顶元素
               if ( p->rchild != NULL && p->rchild != pre )  //p有右子女且未访问过
                    p = p->rchild;	    
               else {                             //说明没有右子树或是右子树回来的（第一次是p的右子树为空，前趋也为空），退栈访问
                    printf ( "%c ", p->data );	//访问
                    pre = p;  p = NULL;           //记忆刚访问过的结点
                    top--; 	                    //转遍历右子树或访问根结点
               }
        }
    } while ( p != NULL || top != -1 );
}

// 利用队列实现二叉树BT的层次序遍历
#define queueSize 30
void levelOrder ( BinTree BT ) {
	BiTNode *Q[queueSize];  int rear = 0, front = 0;
	BiTNode *p = BT;  Q[rear++] = p;	   //根进队
	while ( rear != front ) {		    //队列不空时	
          p = Q[front];  front = (front+1) % queueSize;  
          printf ( "%c ", p->data );	    //退队访问
          if ( p->lchild != NULL ) {      //若有左子女，进队
               Q[rear] = p->lchild;
               rear = (rear+1) % queueSize;
          }        
          if ( p->rchild != NULL ) {     //若有右子女，进队
               Q[rear] = p->rchild;
               rear = (rear+1) % queueSize;
          }
    }
}
