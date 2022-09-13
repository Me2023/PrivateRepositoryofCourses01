#include "SeqStack.cpp"

int BracketsCheck ( char e[ ], int n ) {
//对字符数组e[n]中的表达式进行括号配对检查。
//若括号匹配，函数返回1，否则函数返回0。
    SeqStack S;  initStack(S);	//定义一个栈
    int x;
	for ( int i = 0; i < n; i++ ) 	//顺序扫描e[n]中字符 
        if ( e[i] == '{' || e[i] == '[' || e[i] == '(' ) 
            Push ( S, e[i] ); 	          //左括号进栈
	    else if ( e[i] == '}' ) {
	        if ( stackEmpty(S) ) 
                { printf ("  '{'比'}'少!\n" ); return 0; }
	        if ( getTop(S, x) != '{' ) {
                                printf ( "%c与'}'不配对!\n", getTop(S, x) );
                return 0;
            }
            Pop(S, x);	 		//花括号配对出栈
        }
        else if ( e[i] == ']' ) {
            if ( stackEmpty(S) ) 
                { printf ("缺'['!\n"); return 0; }	
            if ( getTop(S, x) != '[' ) {
                printf ("%c与']'不配对!\n", getTop(S, x) );
                return 0;
            }
                          Pop(S, x);   			//方括号配对出栈
        }
        else if ( e[i] == ')' ) {
            if ( stackEmpty(S) )
                 { printf ("缺'('!\n"); return 0; }	
            if ( getTop(S, x) != '(' ) {
                printf ("%c与')'不配对!\n ", getTop(S, x));
                return 0;
            }
            Pop(S, x);			//圆括号配对出栈
        }
    if ( stackEmpty(S) )               //表达式扫描完且栈空
    	    { printf ("括号配对！\n");  return 1; }
    else { 
        while ( ! stackEmpty(S) )  
            if ( getTop(S, x) == '{' ) 
                { printf ("缺'}' ");  Pop(S, x); }
            else if ( getTop(S, x) == '[' ) 
                { printf ("缺']' ");  Pop(S, x); }
            else if ( getTop(S, x) == '(' )
                { printf ("缺')' ");  Pop(S, x); }	
        printf ("\n");  return 0;
    }
}

            

