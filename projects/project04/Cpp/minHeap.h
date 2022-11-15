#define heapSize 40	      //堆的最大元素个数


typedef struct {
    int weight;             // 结点权值
    char value;             // 结点数据
    int indexInTree;        // 最初索引，用于构造Huffman树
} heapNode;

typedef struct {		    
    // 堆结构的定义
    heapNode elem[heapSize];	// 小根堆存储数组
    int curSize;			    // 当前元素个数
} minHeap;

void creatMinHeap ( minHeap& H, char value[], int fr[], int n );
void siftDown( minHeap& H, int i, int m );
void siftUp ( minHeap& H, int start );
bool Insert ( minHeap& H, heapNode& x );
void siftUp ( minHeap& H, int start );