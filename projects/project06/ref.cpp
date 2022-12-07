#include <iostream>
using namespace std;

template<class Type>
 class BST;
//定义一个类模板的的节点
template<class Type>
class Node{
	friend class BST < Type > ;
public:
	//初始化操作
	Node(Type value = Type(),Node<Type>* left = nullptr,Node<Type>* right =nullptr)
		:data(value), left_child(left), right_child(right){}
	~Node(){
	}
private:
	Type data;
	Node<Type>* left_child;
	Node<Type>* right_child;
};

template<class Type>
class BST{
public:
	BST() :root(nullptr){}
	BST(Type arr[], int len) :root(nullptr){
		for (int i = 0; i < len; ++i){
			Insert(root,arr[i]);
		}
	}
public:
	bool Insert(const Type &value){
		return Insert(root, value);
	}
	bool remove(const Type &value){
		return remove(root, value);
	}
	Type Min()const
	{
		return Min(root);
	}
	Type Max()const
	{
		return Max(root);
	}
	Node<Type>* Search(const Type &value)
	{
		return Search(root, value);
	}
	void Sort()
	{
		Sort(root);
	}
	void SortPair()
	{
		SortPair(root);
	}
	void MakeEmpty()
	{
		MakeEmpty(root);
	}
	~BST(){
		
	}
protected:
	//插入操作
	bool Insert(Node<Type>* &pArr, const Type &value){
		if (pArr == nullptr){
			pArr = new Node<Type>(value);
			return true;
		}
		else if (value < pArr->data){
			Insert(pArr->left_child, value);
		}
		else if (value > pArr->data){
			Insert(pArr->right_child, value);
		}
		else{
			return false;
		}
	}
	//删除操作(首先找到要删除的节点  然后执行删除操作)
	bool remove(Node<Type>* &pArr, const Type &value){
		Node<Type>* New = nullptr;
		if (pArr != nullptr){
			if (value < pArr->data){
				remove(pArr->left_child, value);
			}
			else if (value > pArr->data){
				remove(pArr->right_child, value);
			}
			//找到了我们要删除的节点 删除的四种情况 
			else{
				New = pArr;
				 // 删除叶子节点
				if (pArr->left_child == nullptr && pArr->right_child == nullptr){
					delete pArr; 
					pArr = nullptr;
				}
				//左子树为空 删除右孩子
				else if (pArr->left_child == nullptr && pArr->right_child != nullptr){
					New = pArr;
					pArr = New->right_child;
					delete New;
				}
				//右子树为空 删除左孩子
				else if (pArr->left_child != nullptr &&pArr->right_child == nullptr){
					New = pArr;
					pArr = New->left_child;
					delete New;
				}
				//具有左右子树 ，删除内部节点
				else {
					New = pArr->left_child;
					while (New->right_child != nullptr){
						New = New->right_child;
					}
					pArr->data = New->data;
					remove(pArr->left_child, New->data);
				}
			}
		}
		return true;
	}
	
	//求最小节点
	Type& Min(Node<Type>* pArr)const{
		while (pArr->left_child != nullptr){
			pArr = pArr->left_child;
		}
		return pArr->data;
	}

	//求最大节点
	Type& Max(Node<Type>* pArr)const{
		while (pArr->right_child != nullptr){
			pArr = pArr->right_child;
		}
		return pArr->data;
	}
	//搜索某一个节点
	Node<Type>* Search(Node<Type>* pArr, const Type &value)
	{
		if (pArr == nullptr){
			return nullptr;
		}
		else if(value < pArr->data){
			return Search(pArr->left_child, value);
		}
		else{
			return Search(pArr->right_child, value);
		}
	}

	//节点排序、
	void Sort(Node<Type>* pArr){
		if (pArr != NULL){
			Sort(pArr->left_child);
			cout << pArr->data << " ";
			Sort(pArr->right_child);
		}
	}
	void SortPair(Node<Type>* pArr)
	{
		if (pArr != NULL){
			Sort(pArr->left_child);
			cout << (pArr->data).first << ": "(pArr->data).second << endl;
			Sort(pArr->right_child);
		}
	}
	void MakeEmpty(Node<Type> *&pArr)
	{
		if (pArr != nullptr)
		{
			MakeEmpty(pArr->left_child);
			MakeEmpty(pArr->right_child);
			delete pArr;
		}

	}
private:
	Node<Type>* root;
};


int main(){
	int arr[] = { 5,2,3,1,6,9,7,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	//插入数值方式1
	BST<int> bst;
	for (int i = 0; i < n; ++i){
		bst.Insert(arr[i]);
	}
	
	//插入数值方式2
	//BST<int> bst(arr, n);
	bst.remove(3); 
	int value = 1;
	bst.Sort();
	cout << "Min = " << bst.Min() << endl;
	cout << "Max = " << bst.Max() << endl;
	bst.Search(value);
	return 0;
}
