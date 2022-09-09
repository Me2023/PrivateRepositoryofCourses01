// 多项式
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DefaultSize 20;

// 多项式的存储表示
/* 第一种：静态数组表示
const int maxDegree = 20;   // 最大允许阶数
typedef struct Polynomial {
    int degree;                     // 实际阶数
    float coef[maxDegree+1];        // 系数数组
};
*/

/* 第二种：只保存非零系数项
typedef struct data{
    float coef;
    int exp;
};

typedef struct Polynomial {
    int maxSize;
    int n;
    data *Term;
};
*/

// 第三种：多项式链表
typedef struct node{
    float coef;
    int exp;
    struct node *link;
}Term, *Polynomial;

/* 多项式相加的链表实现
本算法与教材上的算法略有差别，因为它利用了原来两个多项式链表的空间，
没有另外占用存储空间。相加后两个链表都已破坏。
若两个链表长度分别为m和n，算法时间复杂度为O(m+n) */
void AddPolynomial ( Polynomial& A, Polynomial& B, Polynomial& C ) {
    //两个带头结点的按升幂排列的多项式A与B相加，
    //返回结果多项式链表的表头指针 C，结果不另外
    //占用存储, 覆盖 A 和 B 链表
    Term *pa, *pb, *pc, *p, *s;  double a;   int b;
    pc = C;                       //设结果链表C只有头结点
    pa = A->link;            //多项式 A 的检测指针
    pb = B->link;            //多项式 B 
    while ( pa != NULL && pb != NULL ) {
        a = pa->coef;
        // 对应项指数相等
        if ( pa->exp == pb->exp ) { 
            a = pa->coef+pb->coef;  // 系数相加
            p = pb;
            pb = pb->link;
            free (p);               // 指数相等的结点仅保留一个加入结果链
            if ( fabs (a) > 0.001 ) {      // 相加不为零
                pa->coef = a;   pc->link = pa;  pc = pa;
                pa = pa->link;	           // 加入结果链
                }
            else 	      	               // 相加为零, 该项不要
            { p = pa;  pa = pa->link;  free (p); }
        }
        
        // 对应项指数不相等
        else if ( pa->exp > pb->exp ) {	  // pa指数大
            pc->link = pb;   pc = pb;  
            pb = pb->link; 
        }
        else {		  	                  // pb指数大
            pc->link = pa;  pc = pa;
            pa = pa->link;
        }
    } //while结束
    // 剩余部分链入 C 链
    if ( pa != NULL ) pc->link = pa;	
    else pc->link = pb;                   
}



