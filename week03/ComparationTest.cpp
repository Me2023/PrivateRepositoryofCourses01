#include <stdio.h>
#include <stdlib.h>

int main(){
    bool result = true>false; // c没有bool类型，只有c++有
    printf("%d\n",result); // bool类型可比较，以整型格式化输出
}