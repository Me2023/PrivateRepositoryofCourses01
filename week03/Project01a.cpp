// ����˳���Ĳ�����ʵ�����µĺ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define initSize 100 // ��ʼ����
typedef int DataType; // Ԫ�ص���������

DataType remove();  // �������˳���ֱ�������ظ������к�������

// �����õ��ĺ���
// ����˳���
typedef struct {
    DataType *data;
    int n;
    int maxSize;
} SeqList;

// ��ʼ��˳���
void initList(SeqList& L){ 
    L.data = (DataType*)malloc(initSize * sizeof(DataType));
    if(L.data == NULL){
        printf("�洢����ʧ�ܣ�\n"); exit(1);
    }
    L.n = 0; 
    L.maxSize = initSize;
}

// ��彨��˳���
void insertRear(SeqList& L, DataType endTag){
    DataType val;
    scanf("%d", &val); // ����һ����
    while(val != endTag && L.n != L.maxSize){
        L.data[L.n] = val;
        L.n++;
        scanf("%d", &val); // ������һ����
    }
}

// ��ӡ����˳���
void printList(SeqList L){
    printf("[");
    for(int i = 0; i < L.n; i++){
        printf("%d", L.data[i]);
        if(i != L.n - 1)printf(", ");
    }
    printf("]\n");
}

// ��ҵ���ִ���
/* ��˳�����ɾ��������Сֵ��Ԫ�ز��ɺ������ر�ɾԪ�ص�ֵ��
* �ճ���λ�������һ��Ԫ�������˳���Ϊ������ʾ������Ϣ���˳�����
*/
DataType removeMin(SeqList& L){
    DataType ReturnValue;       // �������ر���
    // �����������
    if(L.n == 0) {printf("˳���Ϊ�ձ��޷�ɾ����\n"); exit(1);}
    // ��������
    // ������Сֵ
    DataType min = L.data[0]; // ������Сֵ
    int MinIndex = 0;           // ������Сֵ������ 
    for(int i = 1; i < L.n; i++){
        if(L.data[i] < min) min = L.data[i];
    }
    // ɾ����СֵԪ��
    for(int j = MinIndex-1; j < L.n  - 1; j++){
        L.data[j] = L.data[j+1];        // ������Ԫ��ǰ��
    }
    L.n--;                              // ��ǰ��Ԫ�ظ���-1
    ReturnValue = min;
    return ReturnValue;
}

/* ��˳�����ɾ����i��Ԫ�ز��ɺ������ر�ɾԪ�ص�ֵ
* ���i�������˳���Ϊ������ʾ������Ϣ���˳����� */
DataType remove(SeqList& L, int i){
    // �����������
    if(L.n == 0) {printf("˳���Ϊ�ձ��޷�ɾ����\n"); exit(1);}
    if(i <= 0 || i > L.n) {printf("iȡֵ������\n"); exit(1);}
    // ��������
    DataType ReturnValue = L.data[i-1];       // ��ɾԪ�ص�ֵ�����ں������ر���
    for(int j = i-1; j < L.n  - 1; j++){
        L.data[j] = L.data[j+1];        // ���ν�����Ԫ��ǰ��
    }
    L.n--;                              // ��ǰ��Ԫ�ظ���-1
    return ReturnValue;
}

/* ��˳����е�i��λ�ò���һ���µ�Ԫ��x
* ���i����������ʾ������Ϣ���˳����� */
void insert(SeqList& L, int i, DataType x){
    // �����������
    if(i < 1 || i > L.n + 1) {printf("iȡֵ������\n"); exit(1);}
    if(L.n == L.maxSize) {printf("�������\n"); exit(1);}
    // ��������
    for(int j = L.n-1; j>=i-1; j--) L.data[j+1] = L.data[j]; // ����Ԫ�غ���
    L.data[i-1] = x;    // �ڵ�i��λ�ò���x
    L.n++;              // Ԫ�ظ���+1
}

/* ��˳�����ɾ�����и���ֵx������Ԫ�� */
void removeAll(SeqList& L, DataType x){
    for(int i = 0; i < L.n; i++){
        if(L.data[i] == x) remove(L, i); // ��remove�����Ƴ�����ֵԪ��
    }
}

/* ��˳�����ɾ����ֵ�ڸ���ֵs��t֮�䣨Ҫ��sС��t��������Ԫ��
* ���s��t�������˳���Ϊ������ʾ������Ϣ���˳����� */
void removeBetween(SeqList& L, DataType s, DataType t){
    // �����������
    if(s >= t) {printf("s��tȡֵ������\n"); exit(1);}
    if(L.n == 0) {printf("˳���Ϊ�ձ��޷�ɾ����\n"); exit(1);}
    // ��ȷ����
    for(int i = 0; i < L.n; i++){
        if(L.data[i] > s && L.data[i] < t) remove(L, i); // ��remove�����Ƴ�����������Ԫ��
    }
}

/* ������˳�����ɾ����ֵ�ڸ���ֵs��t֮�䣨Ҫ��sС��t��������Ԫ��
* ���s��t�������˳���Ϊ������ʾ������Ϣ���˳����� */
void removeSortedBetween(SeqList& L, DataType s, DataType t){
    // �����������
    if(s >= t) {printf("s��tȡֵ������\n"); exit(1);}
    if(L.n == 0) {printf("˳���Ϊ�ձ��޷�ɾ����\n"); exit(1);}
    // ��ȷ����
    /* ����˳�����Լ򻯲�������������remove������β����ƶ� */
    /* ���Ҵ���sС��t��Ԫ�ز��� */

}

/* ����������˳���ϲ���һ���µ�����˳����ɺ������ؽ��˳��� */
SeqList merge(SeqList List1, SeqList List2){
    SeqList ReturnList;
    return ReturnList;
}

/* ��˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ��������Ԫ�ص�ֵ������ͬ */
void removeRepeated(SeqList& L){

}

// ����
int main(){
    // ����˳���
    SeqList TestList;
    initList(TestList);
    printf("��������������˳��������, ��999��Ϊ����\n");
    insertRear(TestList, 999);  // ��999ΪendTag
    printf("ԭ˳���Ϊ"); 
    printList(TestList);

    // ��������
    printf("�Ƴ��˵�2��Ԫ��%d\n", remove(TestList, 2));
    
    return 0;
}