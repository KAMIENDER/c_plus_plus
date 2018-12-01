#include<string>
using namespace std;
struct BinaryNode
{
string name;

BinaryNode *left;
BinaryNode *right;

BinaryNode( const string & n = "", BinaryNode *lt =NULL, BinaryNode *rt =NULL )
: name(n), left( lt ), right( rt ) { };
};

BinaryNode* myAnswer(){
BinaryNode* lt = new BinaryNode("is");
BinaryNode* rt = new BinaryNode("simple");
BinaryNode* root = new BinaryNode("This",lt,rt);
return root;
}
