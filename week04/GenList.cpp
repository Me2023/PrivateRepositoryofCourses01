typedef struct node {	//广义表结点定义
    int tag;	
    //＝0为头结点，=1为原子结点，=2是子表结点
    struct node *tlink;	//指向同层下一结点的指针
    union {	      //共用体，此3个域叠压在同一空间
        int ref;	 //tag=0，存放引用计数，设为整数
        char value;	 //tag=1，存放数据，设为单字符
        struct node *hlink;    
            //tag=2，存放指向子表的指针
    } info;
} GenListNode, *GenList;