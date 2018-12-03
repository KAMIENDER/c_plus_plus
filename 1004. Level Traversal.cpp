#include<iostream>
#include<queue>
using namespace std;
template <typename T> struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};
template <typename T>
void levelTraversal(BinaryNode<T>* root, void (*visit)(T &x)){
	if(root==NULL)return;
	queue<BinaryNode<T>*> all;
	while(true){
		visit(root->elem);
		if(root->left!=NULL)all.push(root->left);
		if(root->right!=NULL)all.push(root->right);
		if(all.empty()==true)break;
		root=all.front();
		all.pop();
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
	levelTraversal(all,print);
	return 0;
}
