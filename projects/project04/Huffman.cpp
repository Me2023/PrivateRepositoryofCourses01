#include "Huffman.h"
#define maxWeight 32767

/*
由给定n个权值{w0, w1, w2, …, wn-1}，构造具有n棵二叉树的森林F = { T0, T1, T2, …, Tn-1 }，
其中每棵二叉树Ti只有一个带权值wi的根结点, 其左、右子树均为空。
重复以下步骤, 直到F中仅剩一棵树为止：
    (1) 在F中选取两棵根结点权值最小的二叉树, 做为左、右子树构造一棵新的二叉树。
    置新的二叉树的根结点的权值为其左、右子树上根结点的权值之和。
    (2) 在F中删去这两棵二叉树。
    (3) 把新的二叉树加入F。
*/

// 输入数据value[n]和相应权值fr[n]，构造用三叉链表表示的Huffman树HT
void createHFTree ( HFTree& HT, char value[ ], int fr[ ], int n ) {
	int i, k, s1, s2;  int min1, min2;
	for ( i = 0; i < n; i++ ) {			    // 外结点赋值（0~n-1）
		HT.elem[i].data = value[i];
		HT.elem[i].weight = fr[i];
	}
    for ( i = 0; i < 2*n-1; i++ ) {	        // 指针置空，2n-1是最后总结点数
 	    HT.elem[i].parent = -1;
	    HT.elem[i].lchild =	HT.elem[i].rchild = -1;
	}

	for ( i = n; i < 2*n-1; i++ ) {		    // 逐步构造树，内结点（n~2*n-2)
    
	    min1 = min2 = maxWeight;			// min1是最小权值, min2是次小权值
	    s1 = s2 = 0;						// s1是最小权值点, s2是次小权值点
	    for ( k = 0; k < i; k++ ) {
            if ( HT.elem[k].parent == -1 ) {
                if ( HT.elem[k].weight < min1 ) {	// 最小
                    min2 = min1;  s2 = s1; 		        // 原最小变次小
                    min1 = HT.elem[k].weight;  s1 = k;	// 新最小
                }
                else if ( HT.elem[k].weight < min2 ) 	// 新次小
                { min2 = HT.elem[k].weight;  s2 = k; }
            }
            // 构造新二叉树
            HT.elem[s1].parent = HT.elem[s2].parent = i;    
            HT.elem[i].lchild = s1;  HT.elem[i].rchild = s2;
            HT.elem[i].weight = HT.elem[s1].weight + HT.elem[s2].weight;
        }
    }  
    HT.num = n;  HT.root = 2*n-2; // 外结点数与根
}

