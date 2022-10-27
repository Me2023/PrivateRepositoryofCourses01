#include "Huffman.h"
#include "minHeap.cpp"
#include <iostream>
#include <string>

using std::string; 
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

// 由给定char数组和weight数组，构造哈夫曼树，由引用型参数传递
void createHFTreeWithHeap(HFTree& HT, char value[ ], int fr[ ], int n) {
    int i, k, s1, s2;  
	for (i = 0; i < n; i++) {			    // 外结点赋值（0~n-1）
		HT.elem[i].data = value[i];
		HT.elem[i].weight = fr[i];
	}
    for (i = 0; i < 2*n-1; i++) {	        // 指针置空，2n-1是最后总结点数
 	    HT.elem[i].parent = -1;
	    HT.elem[i].lchild =	HT.elem[i].rchild = -1;
	}
    // 利用最小堆构造哈夫曼树
    minHeap H;
    creatMinHeap(H, value, fr, n);  
    // 生成堆，堆结点是结构体，储存了在原数组中的index数据
    heapNode min1, min2, newHeapNode;      
    // 堆中最小权值、次小权值的结点，构造的新根结点
    for (i = n; i < 2*n-1; i++) {
        // 逐步构造内结点（n~2*n-2)
        Remove(H, min1);    // Remove函数将堆的根节点存至min1中
        Remove(H, min2);
        s1 = min1.indexInTree; s2 = min2.indexInTree;
        // 用这两个结点构造新二叉树
        HT.elem[s1].parent = HT.elem[s2].parent = i;
        HT.elem[i].lchild = s1; HT.elem[i].rchild = s2;
        HT.elem[i].weight = min1.weight + min2.weight;
        HT.elem[i].data = ' '; 
            // 内结点data可以不赋值，没有特别意义
        
        // 对堆进行操作：插入新的根节点
        newHeapNode = {min1.weight + min2.weight, ' ', i}; 
                        // 权值、数据置空、在Huffman树中索引
        Insert(H, newHeapNode);
    } // end of for(i<2n-1)
    HT.num = n;  HT.root = 2*n-2; // 外结点数与根
}

// 对HFTree进行编码，将编码储存进该树中并打印
void encodeHuffman(HFTree& HT) {
    int i, n = HT.num;
    int j, k; string temp;
    printf("index\tdata\tcode\n");  // 打印表头
    for(i = 0; i < n; i++) {
        temp = ""; j = i;
        while (HT.elem[j].parent != -1) { // 该结点有双亲
            k = HT.elem[j].parent;        // 复制该双亲备用
            if(HT.elem[k].lchild == j) {  // 该结点是左孩子
                temp = "0" + temp;
            }
            else if(HT.elem[k].rchild == j) { // 该结点是右孩子
                temp = "1" + temp;
            }
            j = k; // 取其双亲，进入下一循环
        }
        HT.elem[i].HuffmanCode = temp;
        // 打印该结点编码
        printf("%d\t%c\t%s\n", i, HT.elem[i].data, temp.c_str());
    }
}

// 根据给定HFTree和字符串，进行解码
string decodeHuffman(HFTree& HT, string& codeline) {
    // 编码操作
    encodeHuffman(HT);
    string result; result = "";
    // 11000111000101011
    int n = HT.num; int i, j;
    while (codeline.size() != 0) {
        for (i = 0; i < n; i++) {       
            j = codeline.find(HT.elem[i].HuffmanCode);
                // 返回 codeline中 第一个与该字符哈夫曼编码匹配
                // 的子字符串的起始索引，找不到则返回-1
            if (j == 0) {   
                // 如果是在开头就匹配了，可以解码此字符
                codeline.erase(0, HT.elem[i].HuffmanCode.size());
                // 在字符串删除位于首位的该编码
                result += HT.elem[i].data;
                break;
            }
            if (i == 4 && j == -1) exit(1); // 无法匹配，解码失败
        }
    }
    std::cout << "解码结果为：" << result << std::endl;
    return result;
}


void printHFTree (HFTree& HT) {
    // 打印Huffman树表格，不包括编码
    printf("index\tdata\tweight\tparent\tlchild\trchild\n");
    int i;
    for (i = 0; i <= HT.root; i++) {
        printf("%d\t%c\t%d\t%d\t%d\t%d\n", 
        i, HT.elem[i].data,  HT.elem[i].weight,  
        HT.elem[i].parent,  HT.elem[i].lchild,  
        HT.elem[i].rchild);
    }
}

