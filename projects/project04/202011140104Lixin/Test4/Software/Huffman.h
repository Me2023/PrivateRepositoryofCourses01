#define leafNumber 20		   //默认权重集合大小
#define totalNumber 39		   //树结点最大个数
#include <string>
using std::string;      	// 方便处理编码问题

typedef struct {
	char data;			   //结点的值
	int weight;			   //结点的权
	int parent, lchild, rchild;	// 双亲、左、右子女
	string HuffmanCode = "";	// Huffman编码字符串
} HTNode;

typedef struct {
	HTNode elem[totalNumber];   //树存储数组
	int num, root;			   //外结点数与根
} HFTree;

void createHFTreeWithHeap(HFTree& HT, char value[ ], int fr[ ], int n);
void encodeHuffman(HFTree& HT);
string decodeHuffman(HFTree& HT, string& codeline);
void printHFTree (HFTree& HT);