#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 定义是递归的：阶乘函数的递归算法
long Factorial ( long n ) {
    	if (n < 0) exit(0);
    	if (n == 0) return 1;		    //递归终止
    	else return n*Factorial (n-1);	//减一递归
	}

// 数据结构是递归的：单链表，从结构上，用指针定义结点，又用结点定义指针。
typedef struct node { // 链表结点
    int data;  
    struct node *link; // 定义结点用到指针
} LinkNode, *LinkList; // 定义指针用到结点
// 基于递归定义的数据结构，相应算法的实现均可采用递归方式。下面举例。
// 在以 f 为表头指针的不带头结点的单链表中正向打印所有结点所存储的数值。
void printValue ( LinkNode *f ) {
    if ( f != NULL) {		        // 递归结束条件
        printf ( f ->data );	    // 打印当前结点的值
        PrintValue ( f->link );     // 递归打印后续链表
    }
}
// 在以 f 为表头指针的不带头结点的单链表中反向打印所有结点所存储的数值。
void printValue ( LinkNode *f ) {
    if ( f != NULL) {		        // 递归结束条件
        printValue ( f ->link );    // 递归打印后续链表
        printf ( f ->data );	    // 返回后打印结点值
    }
}


/* 问题的解法是递归的：汉诺塔 (Tower of Hanoi) 问题
    如果 n = 1，则将这一个盘子直接从 A 柱移到 C 柱上。否则，执行以下三步：
        - 用 C 柱做过渡，将 A 柱上的(n-1) 个盘子移到 B 柱上：
        - 将 A 柱上最后一个盘子直接移到 C 柱上；
        - 用 A 柱做过渡，将 B 柱上的(n-1) 个盘子移到 C 柱上。
    这是典型的分治法问题。
*/
void Hanoi ( int n, char A, char B, char C ) {
 //用A、B、C代表三个柱子，算法模拟汉诺塔问题
     if (n == 1) printf ( " move %s", A, " to  %s ", C );   
     else {  
		Hanoi ( n-1, A, C, B );
        printf ( " move %s", A, " to  %s ", C );
		Hanoi ( n-1, B, A, C );
     }
}

/* 递归过程改为非递归过程：
    尾递归和单向递归可直接用迭代实现其非递归过程，其他情形必须借助栈实现非递归过程。
*/
// 尾递归用迭代法实现
long Fact ( long n ) {  	    //尾递归改为迭代算法
    long f = 1;
    for ( int i = 2; i <= n; i++ ) f = i*f;
    return f; 
}

// 单向递归用迭代法实现
long FibIter ( long n ) {
    if ( n <= 1 ) return n;
    long a = 0,  b = 1,  c;
    for ( int i = 2;  i <= n; i++ ) {
        c = a+b;             	//求 Fi = Fi-2 + Fi-1
        a = b;   b = c;     	//下一个 Fi-2 = 原来的 Fi-1
    }                            	//下一个 Fi-1 = 原来的 Fi
    return c;
}

// 用栈将递归算法改为非递归算法
typedef struct {
    // 定义栈元素的数据类型
    int m;  char a, b, c;
} item;

void Hanoi ( int n, char A, char B, char C ) { 
    // 求解hanoi塔问题
    item v, w, S[100];   int top = -1;   
    w.m = n;   w.a = A;   w.b = B;   w.c = C;
    S[++top] = w;		//初始布局进栈
    while ( top != -1 ) {        //当栈非空时
        v = S[top--];	        //取栈顶布局，退栈
        if ( v.m == 1 ) printf ("Move disk from peg %c to %c. \n", v.a, v.c );       //直接搬动
        else {
            w.a = v.b;  w.b = v.a;  w.c = v.c;
            w.m = v.m-1;  S[++top] = w;   //(n-1,B,A,C)
            w.a = v.a;  w.b = v.b;  w.c = v.c;
            w.m = 1;  S[++top] = w;	     //(1,A,B,C)
            w.a = v.a;  w.b = v.c;  w.c = v.b;
            w.m = v.m-1;  S[++top] = w;  //(n-1,A,C,B)            }  //end else
        }   //end while
}     //Hanoi

