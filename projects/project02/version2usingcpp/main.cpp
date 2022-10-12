#include "SeqStack.cpp"

#include "Infix_to_Postfix.cpp"
#include "calculateRPN.cpp"

int main() {
    char A[] = "1+2*(3-4)-5/6#";
    char result[20] = {};
    InToPost(A, result);
    printf("运算结果为%f\n",calculateRPN(result));
}
