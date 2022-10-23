#include "HFTree.h"
#define maxWeight 32767
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

