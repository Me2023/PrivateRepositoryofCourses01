#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define defaultSize 256;
typedef struct {
    char *ch;             //串的存储数组
    int maxSize;	   //串数组的最大长度
    int n;           	   //串的当前长度
} HString;

void initStr ( HString& S ) {
//初始化：创建字符串 S 的存储空间并置空串
      S.ch = ( char * ) malloc ((defaultSize+1)*sizeof (char));			  //分配字符数组空间
      if ( S.ch == NULL ) exit (1);   //判断分配成功与否
      S.ch[0] = '\0';			  //置空串
      S.maxSize = defaultSize;  	  //置串的最大字符数
	  S.n = 0;				  //实际字符数置0
}


void createStr ( HString& s, char *init ) {
//从字符数组 init 构造串 s, 要求 s 已存在并初始化
    s.maxSize = defaultSize;
	s.ch = ( char *) malloc (( defaultSize+1 )*sizeof( char )); 
	s.n = strlen ( init );  strcpy ( s.ch, init ); 
}

void copyStr ( HString& s, HString& t ) {
//把串 t 复制给串 s , 要求 s 已存在并初始化
	s.maxSize = defaultSize;
	s.ch = ( char *) malloc (( defaultSize+1 )*sizeof( char ));
}

// 无回溯的模式匹配 KMP 算法
int fastFind ( HString& T, HString& P, int next[ ] ) {
//在目标 T 中寻找模式 P 的匹配位置。若找到，则函
//数返回 P 在 T 中开始字符下标，否则函数返回-1。
//数组next存放 P 的失配函数next[j]值
    int j = 0, i = 0;		            //P与T的扫描指针
	while ( j < P.n && i < T.n ) {	 //对两串扫描
        if ( j == -1 || P.ch[j] == T.ch[i] ) { j++;  i++; }	                         //对应字符匹配，比对位置加一
 	    else j = next[j];   //第 j 位失配，找下一对齐位置
	}
    if ( j < P.n ) return -1; //j 未比完失配，匹配失败
	else return i-P.n;	 //匹配成功
}

// next 失配函数的计算
void getNext ( HString& P, int next[] ) {
    int j = 0, k = -1;
    next[0] = -1;		//初始值
    while ( j < P.n ) 	{//计算next[j]
        while ( k >= 0 && P.ch[j] != P.ch[k] ) 
        k = next[k];	//缩小前缀、后缀子串长度
        j++;  k++;
        next[j] = k;
    }
}