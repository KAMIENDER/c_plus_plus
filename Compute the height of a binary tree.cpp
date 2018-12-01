#include<string>
#include<iostream>
using namespace std;
struct BinaryNode
    {
        string name;
        int size;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const string & n = "", int s = 0, BinaryNode *lt =NULL, BinaryNode *rt =NULL )
            : name(n), size(s), left( lt ), right( rt ) { };
    };
    
int height(const BinaryNode* root){
	if(root == NULL)return -1;
	if(root->left==NULL&&root->right==NULL)return 0;
	int max=0;
	if(root->left!=NULL){
		int h1 = height(root->left);
		max=(max>h1)?max:h1;
	}
	if(root->right!=NULL){
		int h1 = height(root->right);
		max=(max>h1)?max:h1;
	}
	max++;
	return max;
  //insert your code
}

int main(){
	BinaryNode* t1=NULL;
	cout<<height(t1)<<endl;
	BinaryNode* t2=new BinaryNode("1");
	BinaryNode* t3=new BinaryNode("0",0,t2);
	cout<<height(t3)<<endl;
}
