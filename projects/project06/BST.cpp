#include <vector>
#include "AQCondition.cpp"

class BSTNode {
public:
    AQCondition data;     // 数据
    BSTNode *lchild, *rchild;

    // 构造函数
    BSTNode(AQCondition value = AQCondition(), BSTNode *l = NULL, BSTNode *r = NULL) 
    : data(value), lchild(l), rchild(r) {}
};

class BSTree {
public:
    BSTNode *root;  // 指向根结点

    // 构造函数
    BSTree() : root(NULL) {}
    BSTree(vector<AQCondition> arr) : root(NULL) {
        for (int i = 0; i < arr.size(); i++) {
            insert(arr[i]);
        }
    } 

    // 方法
    BSTNode* search(AQCondition &x, BSTNode* &pr);
    bool insert(AQCondition &x); 
};

// 在二叉查找树 BT 中查找关键码等于 x 的结点，成功时函数返回找到结点地址，pr 是其双亲结点
// 不成功时函数返回空，pr 返回最后走到的结点地址
BSTNode* BSTree::search(AQCondition &x, BSTNode* &pr) {
    BSTNode *p = root;  pr = NULL;
	while ( p != NULL && p->data != x ) {
        pr = p;				//向下层继续查找
	    if ( x < p->data ) p = p->lchild;
  	    else p = p->rchild;
	}	
    return p;
}

// 向二叉查找树插入一个结点
bool BSTree::insert(AQCondition &x) {
    BSTNode *s, *p, *f;
	p = search (x, f);                      // 寻找插入位置
	if (p != NULL) return false;            // 查找成功,  不插入
    
	s = new BSTNode(x);
	if (root == NULL) root = s;             // 原为空树，结点为根结点
	else if (x < f->data) f->lchild = s;    // 按左子女插入
	else f->rchild = s;                     // 按右子女插入
	return true;
}

