#define size 100

typedef struct { //并查集类型定义
    int parent[size]; //双亲指针数组
} UFSets;

void Initial ( UFSets& S ) { //初始化
    for ( int i = 0; i < size; i++ )
    S.parent[i] = -1; //每个自成单元素集合
}

int Find ( UFSets& S, int x ) {
    //函数从x 开始，沿双亲链搜索到树的根
    while (S.parent[x] >= 0)
        x = S.parent[x]; //根的parent[]值小于0
    return x;
}

/*
合并操作Merge(UFSets& S, int R1, int R2) 要求把两个不相交集合R1与R2合并为一个集合。
合并的原则是：
① 把元素少的集合合并入元素多的集合；
② R1和R2是两个不相交集合的根。
*/

// 按结点个数合并
int Merge(UFSets& S, int R1, int R2) {
    int x = S.parent[R1] + S.parent[R2]; //元素总个数
    if ( S.parent[R1] <= S.parent[R2] ) { //R1的元素多
        S.parent[R1] = x; //R1成为合并后的根
        S.parent[R2] = R1; return R1;
    }
    else { //否则R2的元素多
        S.parent[R2] = x; //R2成为合并后的根
        S.parent[R1] = R2; return R2;
    }
}

// 按高度合并
int heightMerge ( UFSets& S, int R1, int R2 ) {
//先求高度，再把高度矮的接到高度高的树下面
    int x = S.parent[R1], y = S.parent[R2];
    if ( x <= y ) { //R1高，成为合并后的根
        if ( x == y ) S.parent[R1]--;
        //高度相等, 根高度加一，负数表示应减1
        S.parent[R2] = R1; return R1;
    }
    else { //R2高，成为合并后的根
        S.parent[R1] = R2; return R2;
    }
}

// 压缩元素的查找路径
int CollapsingFind ( UFSets& S, int i ) {
//使用折叠规则压缩路径以提高查找效率
    int j;
    for (j = i; S.parent[j] >= 0; j = S.parent[j]);
    //让j 循双亲指针走到根
    while ( S.parent[i] != j ) {
        int temp = S.parent[i]; //暂存双亲结点地址
        S.parent[i] = j; //让i 的双亲指针指向根
        i = temp; //让i 指向原来i 的双亲
    }
    return j; //返回根
}