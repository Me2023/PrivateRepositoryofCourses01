// 利用顺序表的操作，实现以下的函数
#include <stdio.h>
#include <stdlib.h>
#define initSize 100 // 初始长度
typedef int DataType; // 元素的数据类型

DataType remove();  // 由于题号顺序，又避免代码重复，进行函数声明

// 测试用到的函数
// 定义顺序表
typedef struct {
    DataType *data;
    int n;
    int maxSize;
} SeqList;

// 初始化顺序表
void initList(SeqList& L) { 
    L.data = (DataType*)malloc(initSize * sizeof(DataType));
    if(L.data == NULL) {
        printf("存储分配失败！\n"); exit(1);
    }
    L.n = 0; 
    L.maxSize = initSize;
}

// 后插建立顺序表
void insertRear(SeqList& L, DataType endTag) {
    DataType val;
    scanf("%d", &val); // 读入一数据
    while (val != endTag && L.n != L.maxSize) {
        L.data[L.n] = val;
        L.n++;
        scanf("%d", &val); // 读入下一数据
    }
}

// 打印整数顺序表
void printIntList(SeqList L) {
    printf("[");
    for (int i = 0; i < L.n; i++) {
        printf("%d", L.data[i]);
        if(i != L.n - 1)printf(", ");
    }
    printf("]\n");
}

// 从数组A[n]建立顺序表
void createList(SeqList& L, DataType A[], int n) {
    L.data = (DataType*)malloc(initSize * sizeof(DataType));
    if(L.data == NULL) {
        printf("存储分配失败！\n"); exit(1);
    }
    for (int i = 0; i < n; i++) L.data[i] = A[i];
    L.maxSize = initSize; L.n = n;
}

// 作业部分代码
/* 从顺序表中删除具有最小值的元素并由函数返回被删元素的值，
* 空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行 */
DataType removeMin(SeqList& L) {
    DataType ReturnValue;       // 函数返回变量
    // 出错情况处理
    if(L.n == 0) {printf("顺序表为空表，无法删除！\n"); exit(1);}
    // 正常运行
    // 先找最小值
    DataType min = L.data[0]; // 储存最小值
    int MinIndex = 0;           // 储存最小值的索引 
    for (int i = 1; i < L.n; i++) {
        if(L.data[i] < min) {
            min = L.data[i];
            MinIndex = i;
        }
    }
    // 删除最小值元素
    for (int j = MinIndex; j < L.n - 1; j++) {
        L.data[j] = L.data[j+1];        // 将后面元素前移
    }
    L.n--;                              // 当前表元素个数-1
    ReturnValue = min;
    return ReturnValue;
}

/* 从顺序表中删除第i个元素并由函数返回被删元素的值
* 如果i不合理或顺序表为空则显示出错信息并退出运行 */
DataType remove(SeqList& L, int i) {
    // 出错情况处理
    if(L.n == 0) {printf("顺序表为空表，无法删除！\n"); exit(1);}
    if(i <= 0 || i > L.n) {printf("i取值不合理！\n"); exit(1);}
    // 正常运行
    DataType ReturnValue = L.data[i-1];       // 被删元素的值，用于函数返回变量
    for (int j = i-1; j < L.n - 1; j++) {
        L.data[j] = L.data[j+1];        // 依次将后面元素前移
    }
    L.n--;                              // 当前表元素个数-1
    return ReturnValue;
}

/* 向顺序表中第i个位置插入一个新的元素x
* 如果i不合理则显示出错信息并退出运行 */
void insert(SeqList& L, int i, DataType x) {
    // 出错情况处理
    if(i < 1 || i > L.n + 1) {printf("i取值不合理！\n"); exit(1);}
    if(L.n == L.maxSize) {printf("表溢出！\n"); exit(1);}
    // 正常运行
    for (int j = L.n-1; j>=i-1; j--) L.data[j+1] = L.data[j]; // 后续元素后移
    L.data[i-1] = x;    // 在第i个位置插入x
    L.n++;              // 元素个数+1
}

/* 从顺序表中删除具有给定值x的所有元素 */
void removeAll(SeqList& L, DataType x) {
    for (int i = 0; i < L.n; i++) {
        if(L.data[i] == x) {
            remove(L, i+1); // 用remove函数移除给定值元素
            i--;            // 索引回退1个，否则下次循环会跳过一个元素
        } 
    }
}

/* 从顺序表中删除其值在给定值s与t之间（要求s小于t）的所有元素
* 如果s或t不合理或顺序表为空则显示出错信息并退出运行 */
void removeBetween(SeqList& L, DataType s, DataType t) {
    // 出错情况处理
    if(s >= t) {printf("s和t取值不合理！\n"); exit(1);}
    if(L.n == 0) {printf("顺序表为空表，无法删除！\n"); exit(1);}
    // 正确运行
    for (int i = 0; i < L.n; i++) {
        if(L.data[i] > s && L.data[i] < t) {
            remove(L, i+1);     // 用remove函数移除满足条件的元素
            i--;                // 回退
        } 
    }
}

/* 从有序顺序表中删除其值在给定值s与t之间（要求s小于t）的所有元素
* 如果s或t不合理或顺序表为空则显示出错信息并退出运行 */
void removeSortedBetween(SeqList& L, DataType s, DataType t) {
    // 出错情况处理
    if(s >= t) {printf("s和t取值不合理！\n"); exit(1);}
    if(L.n == 0) {printf("顺序表为空表，无法删除！\n"); exit(1);}
    // 正确运行
    /* 有序顺序表可以简化操作次数，避免remove函数多次操作移动 */
    /* 先找大于s小于t的元素部分 */
    int i, j;
    for (i = 0; i < L.n; i++) {
        // 让i值为第一个要删除的元素的位置，即大于s的第一个数
        if(L.data[i] > s) break;
    }
    if(i == L.n) return;    // 所有元素都比s大的特殊情况，则不删除，直接返回
    for (j = i; j < L.n; j++) {
        // 让j值为最后一个要删除的元素的位置，即小于t的最后一个数
        if(L.data[j] >= t) {j--; break;}    
    }
    if(j == L.n) j--;       // 比s大的所有元素都比t小的特殊情况，让j仍是最后一个要删除元素的位置需要减1

    /* 删除处理 */
    int d = j - i + 1;                      // 删除元素的个数，也是删除之后，其后的元素要前移的位置大小
    for (int k = i; k + d < L.n; k++) {       
        /* k = i: 从位置i处开始将其后第d个元素前移至此位置
         * k + d < L.n: 最后一次循环时，原表位置n-1处移至新表位置n-1-d处（即新表表尾） */
        L.data[k] = L.data[k+d];            // 依次将被删区间之后的元素前移
    }
    L.n -= d;       // 顺序表元素个数减少d个

}

/* 将两个有序顺序表合并成一个新的有序顺序表并由函数返回结果顺序表 */
SeqList mergeList(SeqList List1, SeqList List2) {
    // 建立结果顺序表并初始化
    SeqList ResultList;
    initList(ResultList);
    /*不断将两个表的首元进行比较，将较小的首元摘取至结果表尾。
    * 但本函数不改变原表，也不将原表复制到新表进行“摘取”，而是用数组索引进行处理 */
    int i1 = 0, i2 = 0; 
    // 将List1, List2从位置索引i1, i2处截断，其之前的元素不再考虑，考虑剩余的
    while (i1 < List1.n || i2 < List2.n) { // 这保证了List1和List2至少有一个有“剩余”元素
        if(i1 < List1.n && (i2 == List2.n || List1.data[i1] < List2.data[i2])) {
            // “List1仍有剩余元素”且“其首元小于List2剩余元素首元，或List2没有剩余元素”
            insert(ResultList, ResultList.n + 1, List1.data[i1]); 
            // 这时将List1的“首元”插入结果表尾
            i1 += 1;    // 取List1的下一个“首元”
        }
        else{
            // “List1没有剩余元素（则List2必有剩余元素）”
            // 或“List1, List2都有剩余元素，且List1剩余元素首元大于等于List2剩余元素首元”
            insert(ResultList, ResultList.n + 1, List2.data[i2]);
            // 这时将List1的“首元”插入结果表尾
            i2 += 1;    // 取List2的下一个“首元”
        }
    }
    return ResultList;
}

/* 从顺序表中删除所有其值重复的元素，使表中所有元素的值均不相同 */
void removeRepeated(SeqList& L) {
    for (int i = 0; i < L.n; i++) {           // 遍历元素，被删除的元素不会再被遍历
        for (int j = i + 1; j < L.n; j++) {   // 将i元素与之后的所有元素进行对比
            if(L.data[i] == L.data[j]) {
                // 如果j元素与i元素相同，删除j元素，即第j+1个元素
                remove(L, j+1); 
                j--;   // 删除后索引j回退一个，否则下次循环就跳过了一个元素
                }
        }
    }
}

// 运行，用整数顺序表做测试
int main() {
    SeqList TestList1, TestList2;
    /* 自行建立顺序表
    initList(TestList1);
    printf("请依次输入第一个整数顺序表的数据, 以999作为结束\n");
    insertRear(TestList1, 999);  // 以999为endTag
    printf("原顺序表为"); 
    printIntList(TestList2);
    printf("请依次输入第二个整数顺序表的数据, 以999作为结束\n");
    insertRear(TestList2, 999);  // 以999为endTag
    printf("原顺序表为"); 
    printIntList(TestList2);
    */

    // 函数测试
    DataType A[14] = {1, 2, 3, 4, 5, 6, 5, -1, 4, 3, 2, 7, 8, 1};
    createList(TestList1, A, 14);
    DataType B[8] = {2, 4, 6, 8, 9, 9, 10, 12};
    createList(TestList2, B, 8);

    printf("%d\n",removeMin(TestList1));    // -1
    printIntList(TestList1);                // [1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 7, 8, 1]

    insert(TestList1, 2, 100);
    printIntList(TestList1);                // [1, 100, 2, 3, 4, 5, 6, 5, 4, 3, 2, 7, 8, 1]

    remove(TestList1, 2);                   
    printIntList(TestList1);                // [1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 7, 8, 1]

    removeAll(TestList2, 9);                
    printIntList(TestList2);                // [2, 4, 6, 8, 10, 12]

    removeBetween(TestList1, 2, 6);
    printIntList(TestList1);                // [1, 2, 6, 2, 7, 8, 1]

    removeSortedBetween(TestList2, 2, 11);
    printIntList(TestList2);                // [2, 12]

    removeRepeated(TestList1);
    printIntList(TestList1);                // [1, 2, 6, 7, 8]

    printIntList(mergeList(TestList1, TestList2)); // [1, 2, 2, 6, 7, 8, 12]
    
    return 0;
}