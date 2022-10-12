// 合理运用栈，按照教材中的运算优先级，编程实现任意中缀算术表达式（可以只包含’+’、’-‘、’*’、’/’等双目运算符、小括号和结束符）的求值运算。
// 把中缀算术表达式转化为后缀表达式

// 栈内优先级in stack priority
int isp(char ch) {
    switch(ch) {
        case '#': return 0; break;
        case '+': return 3; break;
        case '-': return 3; break;
        case '*': return 5; break;
        case '/': return 5; break;
        case '%': return 5; break;
        case '(': return 1; break;
        case ')': return 6; break; 
        default: break;
    }
    exit(1);
}

// 栈外优先级in coming priority
int icp(char ch) {
    switch(ch) {
        case '#': return 0; break;
        case '+': return 2; break;
        case '-': return 2; break;
        case '*': return 4; break;
        case '/': return 4; break;
        case '%': return 4; break;
        case '(': return 6; break;
        case ')': return 1; break; 
        default: break;
    }
    exit(1);
}

// 把中缀表达式字符串A转化为后缀表达式，结果存储在result中
void InToPost(char A[], char *result) {
    SeqStack<char> OPND; OPND.Push('#'); // 操作符栈初始化，结束符'#'进栈 
    int i = 0, j = 0; // j是A的索引，用于读取；i是result的索引，用于往里储存
    char ch = A[0]; // 开始扫描
    char op;  op = OPND.getTop(); // op取栈顶元素
    char temp; // 退栈但不输出的临时变量
    while (ch != '#' || op != '#') {
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            // 若ch是操作数，直接输出，读入下一字符
            result[i] = ch; i += 1;
            j += 1; ch = A[j]; 
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '#' || ch == '(' || ch == ')') {  
            // 操作符，判断ch的icp和位于栈顶的操作符op的isp
            if (icp(ch) > isp(op)) {
                // 栈外优先级高，进栈，读入下一字符
                OPND.Push(ch); op = OPND.getTop();
                j += 1; ch = A[j];
            }
            else if (icp(ch) < isp(op)) {
                // 栈内优先级高，退栈并输出
                result[i++] = OPND.Pop();
                op = OPND.getTop();
            }
            else if (icp(ch) == isp(op)) {
                // 栈内栈外优先级相同，退栈但不输出（只可能是两个左括号或右括号）
                // 如果退出的是'('，读入下一字符
                temp = OPND.Pop(); op = OPND.getTop();
                if (temp == '(') {
                    j += 1;
                    ch = A[j];
                }
            }
            result[i] = '#';
        }
        else {
            printf("有非法字符，无法转换！"); exit(1);
        }
    }
    printf("%s 转化为后缀表达式为 %s\n", A, result);
} 


