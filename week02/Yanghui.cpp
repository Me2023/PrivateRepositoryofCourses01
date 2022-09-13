#include "LinkQueue.cpp"

void Yanghui ( int n ) {
	LinkQueue Q;                                //创建队列Q
    initQueue (Q);
	enQueue(Q, 1);  enQueue(Q, 1);              //第 1 行系数进队 
    int s = 0, t;
    for (int i = 1; i <= n; i++ ) {             //逐行输出
        printf ("\n");					
        enQueue (Q, 0);					
        for ( int j = 1; j <= i+2; j++ ) {      //下一行
            deQueue(Q, t);   enQueue(Q, s+t);   //计算下一行系数, 并进队列 		
            s = t;
            if ( j != i+2 ) printf ("%d", s);	 //输出一个系数
        }
    }
}

