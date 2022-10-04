// 将中缀表达式转化为后缀表达式，然后利用栈对该后缀表达式求值，从而计算出原中缀表达式的值
#include <stdio.h>
#include <math.h>
#include "doubleSeqStack.cpp"

// 对输入的后缀表达式字符串进行扫描和计算，返回计算结果。
double calculateRPN(char A[]) {
    // 对以字符"#"结束的后缀表达式字符串进行计算。如果不是可计算的后缀表达式，显示出错信息并退出
    /* 顺序扫描表达式的每一项，然后根据它的类型做如下相应操作，
    如果该项是操作数，则将其压入栈中；
    如果该项是操作符<op>，则连续从栈中退出两个操作数Y和X，形成运算指令X<op>Y，并将计算结果重新压入栈中。
    当表达式的所有项都扫描并处理完后，栈顶存放的就是最后的计算结果。*/
    SeqStack OPND; initStack (OPND);    // 存放操作数和计算结果的栈
    double result; int i = 0; double Y, X;  //结果数，字符串扫描指针，两个存放退栈的操作数的变量
    char ch = A[i++];
    while (ch != '#') {
        if (ch >= '0' && ch <= '9') OPND.elem[++OPND.top] = (double)(ch - '0'); // 操作数，进栈
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {  // 操作符，退栈操作数，进行运算
            if (OPND.top < 1) {printf("可能输入了错误的后缀表达式，无法运算！\n"); exit(1);}
            Pop(OPND, Y); Pop(OPND, X); // 如果栈中有至少两个操作数，连续退栈
            switch (ch) {   // 形成运算指令，并将结果入栈
                case '+': Push(OPND, X + Y); break;
                case '-': Push(OPND, X - Y); break;
                case '*': Push(OPND, X * Y); break;
                case '/': Push(OPND, X / Y); break;
                default: break;
            }
        }
        else {
            printf("有非法字符，无法运算！"); exit(1);
        }
    }
    return OPND.elem[OPND.top];
}


