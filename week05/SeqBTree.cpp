#include "SqBTree.h"
int createSqBTree ( SqBTree& BT, char a[ ][3], int n ) {
//从字符数组 a 中按层输入 n 条分支，建立二叉树BT
//的顺序存储表示BT，函数返回实际占用存储个数
	int i, j, k = 0;
  	for ( i = 0; i < maxSize; i++ ) BT.data[i] = '#'; //初始化
	BT.data[k] = a[0][0];	    //根是第一个分支的双亲
	for ( i = 0; i < n; i++ ) {	    	//逐个分支处理
        for ( j = 0; j <= k; j++ )	//查各分支双亲位置
            if ( a[i][0] == BT.data[j] )	//查到
               if ( a[i][2] == ‘0’ ) {     //插入左分支
                                   BT.data[2*j+1] = a[i][1];  k = 2*j+1;
                    break;
                }
                else {                    //插入右分支
                    BT.data[2*j+2] = a[i][1];  k = 2*j+2;
                    break;
               }			
    }
    BT.n = n;  return k;
}
