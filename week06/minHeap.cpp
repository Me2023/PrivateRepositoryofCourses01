#include "minHeap.h"
void siftDown(minHeap& H, int i, int m );
// 小根堆的建立
void creatMinHeap ( minHeap& H, HElemType arr[ ], int n ) {
//将一个数组从局部到整体，自下向上调整为小根堆
    for ( int i = 0; i < n; i++ ) H.elem[i] = arr[i];    //复制
	H.curSize = n;	
	for ( int i = (H.curSize-2)/2; i >= 0; i-- )	
			//自底向上逐步扩大小根堆
	     siftDown ( H, i, H.curSize-1 );
			//局部自上向下筛选
};

// 小根堆的向下筛选算法
void siftDown ( minHeap& H, int i, int m ) {
//从结点i开始到m为止, 自上向下比较, 将一个集合局
//部调整为小根堆
	HElemType temp = H.elem[i]; 
	for ( int j = 2*i+1; j <= m; j = 2*j+1 ) {
	    if ( j < m && H.elem[j] > H.elem[j+1] ) j++;
	    if ( temp <= H.elem[j] ) break;	//小则不做调整
	    else { H.elem[i] = H.elem[j];  i = j; }     //小者上移
	}
	H.elem[i] = temp;	 //回放temp中暂存的元素
}
