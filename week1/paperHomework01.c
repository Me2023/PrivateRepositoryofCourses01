#include <stdio.h>
#define maxN 100 // 数组最大长度
int n; // 整数个数，全局变量

int main(){
    // 声明函数
    int *getArray();
    int printArray();
    int maxSum();
    // 输入参数，得到数组
    printf("请输入整数个数：\n");
    scanf("%d", &n);
    int *array = getArray(n);
    /* 一些预设数组，需要输入 n = 6，用到时可以把第13行加上 "//"
    int array[6] = {-2, 11, -4, 13, -5 ,2};
    int array[6] = {11, -4, 13, -2, -5 ,2};
    int array[6] = {2, -5 ,-2, 11, -4, 13};*/
    // 最大子序列求和
    maxSum(array);
    return 0;
}


// 得到指定长度 n 的整数数组，输入每个元素后按回车键，长度不大于maxN
int *getArray(int n){
    static int array[maxN], i; // C不支持在调用函数时返回局部变量的地址，除非定义局部变量为 static 变量
    for(i = 0; i < n; i++){
        printf("请输入第 %d 个整数：\n", i+1);
        scanf("%d", &array[i]);
    }
    return array;
}

// 打印整数数组，这里长度要用到全局变量 n
int printArray(int *array){
    int i;
    for(i = 0; i < n; i++)printf("%d ", array[i]);
    return 1;
}

// 穷举法求最大子序列和，返回这个和。这里长度要用到全局变量 n
int maxSum(int *array){
    int newMaxSum = 0, temp = 0, i, j, k;
    int init = 0, final = 0;
    for(i=0; i<n; i++){                 // 起始元素，从[0]到[n-1]
        for(j=n-1; j>=i; j--){          // 终止元素，从[n-1]到[i]
            for(k=i; k<=j; k++){        // 起始到终止元素的遍历求和
                temp = temp + array[k];
            }
            if(temp >= newMaxSum){  
                // 最大值及其对应子列信息的存储
                newMaxSum = temp;
                init = i+1; final = j+1;
            }
            temp = 0;
        }
    }
    printf("从第 %d 个整数到 第 %d 个整数求和，有最大值 %d\n", init, final, newMaxSum);
    return newMaxSum;
}