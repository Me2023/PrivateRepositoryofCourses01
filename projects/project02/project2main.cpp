#include <iostream>
#include <string>
#include "calculateRPN.cpp"
#include "Infix_to_Postfix.cpp"
using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
    char *TestStr; 
    //cout << "请输入后缀表达式" << endl;
    //cin << TestStr;
    TestStr = "1+2*(3-4)-5/6#";
    InToPost(TestStr);
    
}