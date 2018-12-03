#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef int T;
struct treeNode {
  T data;
  struct treeNode *left, *right;
  treeNode(T d, treeNode *l=NULL, treeNode *r=NULL):data(d),left(l),right(r){};
};
queue<const treeNode*> all;
int width(const treeNode * root){
	if(root==NULL)return 0;
	const treeNode* ptr=root;
	int max=0;
	int now=0;
	all.push(ptr);
	while(true){
		now=all.size();
		max=max>now?max:now;
		while(now>0){
			now--;
			ptr=all.front();
			all.pop();
			if(ptr->left!=NULL)all.push(ptr->left);
			if(ptr->right!=NULL)all.push(ptr->right);
		}
		if(all.empty()==true)break;
	}
	return max;
};
treeNode* buildTree(const string &preorder, const string &inorder){
	if(preorder==""&&inorder=="")return NULL; 
	char now=preorder[0];
	int pos=inorder.find_first_of(now);
	treeNode* root=new treeNode(now);
	if(pos>0)root->left=buildTree(preorder.substr(1,pos),inorder.substr(0,pos));
	if(pos<inorder.size()-1)root->right=buildTree(preorder.substr(1+pos),inorder.substr(pos+1));
	return root;
};
int main(){
	string a;
	cin>>a;
	string b;
	cin>>b;
	treeNode* head=buildTree(a,b);
	cout<<width(head);
}


