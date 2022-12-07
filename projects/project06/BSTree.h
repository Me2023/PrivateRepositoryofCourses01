#include <vector>



template<class T>
class Node {
public:
    T data;     // 数据
    Node<T> *lchild, *rchild;

    Node(T value = T(), Node<T> *l = NULL, Node<T> *r = NULL) 
    : data(value), lchild(l), rchild(r) {}

};

template<class T>
class BSTree {
public:
    Node<T> *root;  // 指向根结点

    // 构造函数
    BSTree() : root(NULL) {}
    BSTree(vector<T> arr) : root(NULL) {
        for (int i = 0; i < arr.size(); i++) {
            insert(root, arr[i], 0);
        }
    } 

    // 方法
    Node<T> *search (const int x) = 0;
    bool insert(Node<T>* &root, T x, int key); // 插入，引用指针可以改变指针本身（地址），指向新的地址
};

template<class T>
Node<T>* BSTree<T>::search (const int x) {

}