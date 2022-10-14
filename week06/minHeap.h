#define heapSize 40	      //堆的最大元素个数
typedef int HElemType;	      //堆中元素的数据类型
typedef struct {		      //堆结构的定义
    HElemType elem[heapSize];	//小根堆存储数组
    int curSize;			//当前元素个数
} minHeap;
