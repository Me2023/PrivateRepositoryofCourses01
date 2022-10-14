#include "minHeap.cpp"
#include <stdio.h>
int main() {
    minHeap H;
    int arr[20] = {13, 5, 10, 7, 27, 9, 4, 15, 33, 20};
    creatMinHeap(H, arr, 10);
    for(int i = 0; i < 10; i++) printf("%d\n", H.elem[i]);
}