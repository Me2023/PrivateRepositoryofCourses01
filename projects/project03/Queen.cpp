#include <stdio.h>
int queen[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int count = 0;

bool check(int i, int a) {
    // 判断是否冲突
    int j, b;
    for (j = 0; j < i; j++) {
        b = queen[j];
        if (b == a || i - a == j - b || i + a == j + b) {
            // 有同行/副对角线/主对角线元素
            return false;
        } 
    }
    return true;
}

// 递归算法
void putQueen(int i) {
    // 从第i行开始放皇后，要求第i行之前已经放好。
    for (int a = 0; a < 8; a++) {
        if (check(i, a)) {
            queen[i] = a;
            if (i == 7) {
                // 这行放好后，八行全部放好了，输出该放法
                count += 1;
                for (int j = 0; j < 8; j++) printf("%d ", queen[j]);
                printf("\n");
            }
            else putQueen(i + 1); // 这行放好后，还有下一行，进入下一行
        } // endif (check(i, a))
        // check后，试下一个数，进入下一轮循环。a=8时自动结束此层递归
    }
}

// 非递归算法
void putQueenIter() {
    int a = 0;
    for (int i = 0; i < 8; i++) {
        if (i == -1) break;     // 判断是否都试完了，退出循环

        for (; a < 8; a++) {
            // 对给定的第i行进行试数
            if (check(i, a)) {
                queen[i] = a;
                // 如果是最后一行：
                if (i == 7) {
                    // 是可行解，计数并打印
                    count++;
                    for (int j = 0; j < 8; j++) printf("%d ", queen[j]);
                    printf("\n");
                    continue;   // 不进入下一行，继续试数，直到a=8
                } 
                // 不是最后一行，第i行满足了，进入下一行：
                a = 0; // 进入下一行前调整a，即要重新从0试数
                break; // 进入下一行
            } 
        } // endfor (; a < 8; a++)

        // 该行所有数都试过了（有可能已经成功并输出了，也有可能失败，这无关紧要）
        if (a == 8) {
            // 回溯：再让前一行试下一个数。没有前一行可回溯了则结束算法
            a = queen[--i];
            a++;
            queen[i] = -1;
            i--;        // 与for循环中i++抵消
        }
    } // endfor (i = 0; i < 8; i++) 
}

