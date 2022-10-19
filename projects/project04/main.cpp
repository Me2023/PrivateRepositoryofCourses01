/*
利用最小堆编程实现给定权值集合下构造相应霍夫曼树的算法，并解决以下问题：
有一电文共使用五种字符a,b,c,d,e,其出现频率依次为4,7,5,2,9。
(1)构造对应的编码哈夫曼树(要求左子树根结点的权小于等于右子树根结点的权)。
(2)给出每个字符的哈夫曼编码。
(3)译出编码系列11000111000101011的相应电文。
*/
#include "Huffman.h"
#include "minHeap.cpp"
#include <stdlib.h>

// 利用最小堆构造哈夫曼树
void createHFTree(HFTree& HT, char value[ ], int fr[ ], int n) {
    int i, k, s1, s2;  
	for (i = 0; i < n; i++) {			    // 外结点赋值（0~n-1）
		HT.elem[i].data = value[i];
		HT.elem[i].weight = fr[i];
	}
    for (i = 0; i < 2*n-1; i++) {	        // 指针置空，2n-1是最后总结点数
 	    HT.elem[i].parent = -1;
	    HT.elem[i].lchild =	HT.elem[i].rchild = -1;
	}
    minHeap H;
    heapNode min1, min2;         // 最小权值和次小权值
    creatMinHeap(H, value, fr, n);

    for (i = n; i < 2*n-1; i++) {
        Remove(H, min1);
        Remove(H, min2);
        HT.elem[i-n].data = min1.value;
        HT.elem[i-n].weight = min1.weight;
        HT.elem[i+1-n].data = min2.value;

    }


}