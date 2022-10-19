#include "minHeap.h"
#include <string.h>
void siftDown( minHeap& H, int i, int m );
void siftUp ( minHeap& H, int start );

// 小根堆的建立
void creatMinHeap ( minHeap& H, char value[], int fr[], int n ) {
// 将一个数组从局部到整体，自下向上调整为小根堆
    for ( int i = 0; i < n; i++ ) {
		H.elem[i].weight = fr[i];    //复制，完全二叉树
		H.elem[i].value = value[i];
	}
	H.curSize = n;	
	for ( int i = (H.curSize-2)/2; i >= 0; i-- )	
			// 自底（最后一个非叶结点，即第一个叶结点的父结点）向上逐步扩大小根堆
	     siftDown ( H, i, H.curSize-1 );
			// 局部自上向下筛选
}

// 小根堆的向下筛选算法
void siftDown ( minHeap& H, int i, int m ) {
// 从结点i开始到m为止, 自上向下比较, 将一个集合局部调整为小根堆
	heapNode temp = H.elem[i]; 
	for ( int j = 2*i+1; j <= m; j = 2*j+1 ) { 			// j是i的左孩子
	    if ( j < m && H.elem[j].weight > H.elem[j+1].weight ) j++; 	// 存在左孩子和右孩子，左孩子和右孩子谁大谁小
	    if ( temp.weight <= H.elem[j].weight ) break;					// 小则不做调整
	    else { H.elem[i] = H.elem[j];  i = j; }     	// 小者上移
	}
	H.elem[i] = temp;	 // 回放temp中暂存的元素
}

//从小根堆中删除堆顶元素并通过引用参数 x 返回
bool Remove ( minHeap& H, heapNode& x ) {	
	if ( H.curSize == 0 ) return false;	//堆空, 返回
	x = H.elem[0]; 		//返回最小元素
	H.elem[0] = H.elem[H.curSize-1];							//最后元素填补到根结点
	H.curSize--; 
	siftDown ( H, 0, H.curSize-1 );    //从新调整为堆
	return true;					
}
