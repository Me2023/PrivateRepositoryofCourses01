#include "Queen.cpp"
#include <stdio.h>

int main() {
	printf("递归算法\n");
    putQueen(0);
    printf("递归算法解的个数%d\n", count);

    for (int i = 0; i < 8; i++)queen[i] = -1;
    count = 0;

	printf("非递归算法\n");
    putQueenIter();
    printf("非递归算法解的个数%d\n", count);
}