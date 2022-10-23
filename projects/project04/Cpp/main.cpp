/*
利用最小堆编程实现给定权值集合下构造相应霍夫曼树的算法，并解决以下问题：
有一电文共使用五种字符a,b,c,d,e,其出现频率依次为4,7,5,2,9。
(1)构造对应的编码哈夫曼树(要求左子树根结点的权小于等于右子树根结点的权)。
(2)给出每个字符的哈夫曼编码。
(3)译出编码系列11000111000101011的相应电文。
*/
#include "Huffman.cpp"
#include <iostream>
#include <string>

using std::string; 


int main() {
    char value[] = "abcde"; int weight[] = {4, 7, 5, 2, 9};
    HFTree HT;
    createHFTreeWithHeap(HT, value, weight, 5);
    printHFTree(HT);
    printf("    Huffman编码表\n");
    encodeHuffman(HT);
    string codeline("11000111000101011");
    std::cout << decodeHuffman(HT, codeline) << std::endl;
}