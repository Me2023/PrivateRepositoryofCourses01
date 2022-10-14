#include "SeqStack.cpp"
#include "Infix_to_Postfix.cpp"
#include "calculateRPN.cpp"

int main() {
    char A[] = "1+2*(3-4)-5/6#";
    char result[20] = {};
    InToPost(A, result);
    printf("%s 转化为后缀表达式为 %s\n", A, result);
    printf("运算结果为%f\n",calculateRPN(result));      // -1.833333

    char B[] = "2-3+4*5/(6+7)#";
    result[20] = {};
    InToPost(B, result);
    printf("%s 转化为后缀表达式为 %s\n", B, result);
    printf("运算结果为%f\n",calculateRPN(result));      // 0.538462
}
