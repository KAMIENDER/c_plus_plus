#include<string>
#include<iostream>
#include<stack>
using namespace std;
template <typename T> struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};

template <typename T>
void inorder_recursive(BinaryNode<T>* root, void (*visit)(T &x)){
	if(root==NULL)return;
	inorder_recursive(root->left,visit);
	visit(root->elem);
	inorder_recursive(root->right,visit);
}

 

template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x)){
	stack<BinaryNode<T>* > all;
	while(true){
		all.push(root);
		if(root->left!=NULL){
			root=root->left;
		}
		else {
			if(all.empty()==true)break;
			BinaryNode<T>* temp;
			do{
				temp=all.top();
				all.pop();
				visit(temp->elem);
			}while(temp->right==NULL&&all.empty()==false);
			root=temp->right;
			if(root==NULL)break;
		}
	}
}
template <typename D>
 void InitBiTree(BinaryNode<D>* &T)//构造空二叉树
{
    T=NULL;
}
template <typename D>
void CreateBinaryNode(BinaryNode<D>* &T)//生成二叉树
{
   	char ch;
	cin>>ch;
	//cout<<ch;
   	if(ch=='0')T=NULL;
	else{
	//生成根结点
		T=new BinaryNode<D>('0');
		if(T==NULL)
		{
			cout<<"生成结点错误！"<<endl;
			return;
		}
		T->elem=ch;
		CreateBinaryNode(T->left);
		CreateBinaryNode(T->right);
   }
}
template<typename T>
void print(T x){
	cout<<x<<" ";
}
int main(){
	BinaryNode<char> *all;
	InitBiTree(all);
	CreateBinaryNode(all);
	inorder(all,print);
	return 0;
}
