#include<iostream>
#include<string>
#include<queue>
using namespace std;
template <typename T> struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};
BinaryNode<char>* buildTree(const string &preorder, const string &inorder){
	if(preorder==""&&inorder=="")return NULL; 
	char now=preorder[0];
	int pos=inorder.find_first_of(now);
	BinaryNode<char>* root=new BinaryNode<char>(now);
	if(pos>0)root->left=buildTree(preorder.substr(1,pos),inorder.substr(0,pos));
	if(pos<inorder.size()-1)root->right=buildTree(preorder.substr(1+pos),inorder.substr(pos+1));
	return root;
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
template<typename T>
void print(T x){
	cout<<x<<" ";
}
int main(){
	BinaryNode<char>* head;
	string a;
	cin>>a;
	string b;
	cin>>b;
	head=buildTree(a,b);
	levelTraversal(head,print);
	return 0;
}
