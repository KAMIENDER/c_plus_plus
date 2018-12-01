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
	visit(root->elem);
	if(root->left!=NULL)inorder_recursive(root->left,visit);
	if(root->right!=NULL)inorder_recursive(root->right,visit);
}

 

template <typename T>
void inorder(BinaryNode<T>* root, void (*visit)(T &x)){
	stack<BinaryNode<T> > all;
	while(root!=NULL){
		visit(root->elem);
		if(root->left!=NULL){
			if(root->right!=NULL)all.push(root->right);
			root=root->left;
		}
		else{
			if(all.empty()==false){
				root=all.top();
				all.pop();
			}
			else root=NULL;
		}
	}
}

void main(){
	
}
