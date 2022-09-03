#include <stdio.h>
#include <stdlib.h>

int main(){
	void printN(int N);
	void printNN(int N);
    int n;
    scanf("%d",&n);
    printN(n);
}

void printN(int N){
    int i;
    for(i=1;i<=N;i++){
        printf("%d\n",i);
    }
    return;
}

void printNN(int N){
    if(N){
        printNN(N-1);
        printf("%d\n",N);
    }
    return;
}

