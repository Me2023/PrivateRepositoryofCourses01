
#define maxSize 128
    typedef char TElemType;          //元素数据类型
    typedef struct {
        TElemType data[maxSize];	   //存储数组
        int n;				   //当前结点个数
    } SqBTree;
