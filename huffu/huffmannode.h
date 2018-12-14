#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<cstdio>
#include<fstream>
#include<utility>
#include<algorithm>
#include<stack>
#include<bitset>
#include<cmath>
#define max 270
using namespace std;
struct Node{
	char c;
	int weught;
	string code;
	Node* left;
	Node* right;
	Node* parent;
};
class huff{
	private:
		map<char,string> hash;
		map<string,char> decodeout;
		fstream infile;
		ofstream outfile;
		Node* root;
		string inf;
		int size;
		int height;
		vector<pair<char,int> > fre;
		void cbit(bitset<8> in);
		void clear(Node* &ptr){
			if(ptr==NULL)return;
			if(islevea(ptr)){
				delete ptr;
				return;
			}
			clear(ptr->left);
			clear(ptr->right);
			delete ptr;
		}
		void strtonum(string in);
		void strtonum2();
		void print(const Node* ptr){
			if(islevea(ptr))cout<<ptr->c<<" ";
			else{
				print(ptr->left);
				print(ptr->right);
			}
		};
		bool islevea(const Node* ptr){
			return (ptr->left==NULL&&ptr->right==NULL);
		}
		void createfresv();
		void buildtree();
		void encode();
		void encodepri(Node* ptr,string code);
		void enoutput();
		void mapc(char &c,int &wid,unsigned int &code);
		void deoutput();
		string cts(char &in);
	public:
		huff(){
			root=NULL;
			size=0;
			height=0;
		}
		~huff(){
			clear(root);
			infile.close();
			outfile.close();
		}
		void openinfile(const string &in);
		void openoutfile(const string &out);
		void openddecodefile(const string &in);
		void opendputdecoded(const string &out);
		void rebuildtree();
		void Encode();
};
void huff::Encode(){
	this->createfresv();
	this->buildtree();
	this->encode();
	this->enoutput();
}
bool treecmp(Node* a,Node* b){
	return a->weught>b->weught;
}
bool frecmp(pair<char,int> a,pair<char,int> b){
	return a.second>b.second; 
}
void huff::strtonum(string in){
	size_t m=in.size();
	bitset<8> out;
	int i=0;
	int key=1;
	for(int t=0;t<m;t++){
		if(in[t]=='1')out.set(7-i,1);
		i++;
		key=1;
		if(i==8){
			i=0;
			key=0;
			cbit(out);
		}
	}
	if(key)cbit(out);
}
void huff::createfresv(){
	char a;
	int all[max]={0};
	while((a=infile.get())!=EOF){
		all[a]++;
	}
	for(int t=0;t<max;t++){
		if(all[t]!=0){
			fre.push_back(pair<char,int>(t,all[t]));
		}
	}
	sort(fre.begin(),fre.end(),frecmp);
}
void huff::openoutfile(const string &out){
	outfile.open(out,ios::out | ios::binary);
}
void huff::openinfile(const string &in){
	infile.open(in);
	inf=in;
}
void huff::buildtree(){
	if(fre.size()==0)return;
	Node* ptr;
	vector<Node*> all; 
	for(int t=0;t<fre.size();t++){
		ptr=new Node;
		ptr->c=fre[t].first;
		ptr->weught=fre[t].second;
		ptr->parent=NULL;
		ptr->left=NULL;
		ptr->right=NULL;
		all.push_back(ptr);
		cout<<ptr->c<<" ";
	}
	cout<<endl;
	while(all.size()>1){
		Node* temp1=all.back();
		all.pop_back();
		Node* temp2=all.back();
		all.pop_back();
		cout<<temp1->c<<" "<<temp2->c<<endl; 
		ptr=new Node;
		ptr->weught=temp1->weught+temp2->weught;
		ptr->left=(temp1->weught>temp2->weught)?temp2:temp1;
		ptr->right=(temp1->weught>temp2->weught)?temp1:temp2;
		temp2->parent=temp1->parent=ptr;
		ptr->parent=NULL;
		all.push_back(ptr);
		sort(all.begin(),all.end(),treecmp);
	}
	cout<<"test"<<endl;
	root=all.back();
	all.pop_back();
	print(root);
	cout<<endl;
}
void huff::encode(){
	if(root==NULL)return;
	Node* ptr=root;
	string code="";
	encodepri(ptr,code);
}
void huff::encodepri(Node* ptr,string code){
	if(islevea(ptr)){
		hash[ptr->c]=code;
		size++;
		height=(height>code.size())?height:code.size();
		cout<<ptr->c<<" "<<hash[ptr->c]<<endl;
		return;
	}
	encodepri(ptr->left,code+"0");
	encodepri(ptr->right,code+"1");
}
void huff::cbit(bitset<8> in){
		outfile<<(unsigned char)in.to_ulong();
}
void huff::enoutput(){
	auto itor=hash.begin();
	for(int t=0;t<hash.size();t++){
		outfile.write((char*) &(*itor).first,sizeof((*itor).first));
		outfile<<(*itor).second.size();
		outfile<<endl;
		strtonum((*itor).second);
		if(t!=hash.size()-1)outfile<<endl;
		itor++;
	}
	outfile<<'e';
	strtonum2();
}
void huff::strtonum2(){
	char a;
	infile.close();
	infile.open(inf);
	int i=0;
	int m=0;
	string out;
	bitset<8> temp;
	bitset<8> zero;
	int key=0;
	if((a=infile.get())==EOF)return;
	//cout<<a<<endl;
	out=hash[a];
	while(true){
		//cout<<i<<" ";
		if(i==8){
			cbit(temp);
			temp&=zero;
			key=0;
			i=0;
		}
		if(m==out.size()){
			m=0;
			if((a=infile.get())==EOF)break;
			out=hash[a];
		}
		temp.set(7-i,out[m++]-'0');
		//cout<<temp<<endl;
		i++;
		key=1;
	}
	if(key){
		cout<<temp;
		cbit(temp);
	} 
}
void huff::openddecodefile(const string &in){
	infile.open(in,ios::binary | ios::in);
}
void huff::opendputdecoded(const string &out){
	outfile.open(out,ios::out);
}
void huff::rebuildtree(){
	//读取数据 
	char test[3];//这里有bug 
	char c;
	char rb;
	int nodes;
	int wid;
	/*
	infile.read(test,3);
	string line(test);
	nodes=stoi(line);
	cout<<nodes<<endl;*/
	while(true){
		char code;
		infile.read(&c,1);
		cout<<c<<endl;
		infile.read(&code,1);
		wid=code-'0';
		cout<<wid<<endl;
		infile.read(&rb,1);
		infile.read(&code,1);
		infile.read(&rb,1);
		unsigned int cod=(unsigned int)code;
		//cout<<code<<endl;
		mapc(c,wid,cod); 
		cout<<hash[c]<<endl;
		if(rb=='e')break;
	}
	
	//根据hash表重建树 
	auto itor=hash.begin();
	for(int t=0;t<hash.size();t++){
		string code=(*itor).second;;
		c=(*itor).first;
		//cout<<c<<" "<<code<<endl;
		Node* ptr;
		if(root==NULL){
			//cout<<"root"<<endl;
			root=new Node;
			root->left=NULL;
			root->right=NULL;
			root->parent=NULL;
		}
		ptr=root;
		for(int t=0;t<=code.size();t++){
			//cout<<code[t];
			if(t==code.size()){
				//cout<<"3 ";
				ptr->code=code;
				ptr->c=c;
				ptr->left=NULL;
				ptr->right=NULL;
				continue;
			}
			if(code[t]=='0'){
				//cout<<'0'<<" ";
				if(ptr->left==NULL){
					//cout<<"try"<<endl; 
					Node* ptr0=new Node;
					ptr0->parent=ptr;
					ptr0->left=NULL;
					ptr0->right=NULL;
					ptr->left=ptr0;
				}
				ptr=ptr->left;
			}
			else{
				//cout<<'1'<<" ";
				if(ptr->right==NULL){
					//cout<<"try"<<endl; 
					ptr->right=new Node;
					Node* ptr0=ptr->right;
					ptr0->parent=ptr;
					ptr0->left=NULL;
					ptr0->right=NULL;
				}
				ptr=ptr->right;
			}
			//cout<<"end"<<endl;
		}
		itor++;
	}
	//print(root);
	deoutput();
}
void huff::mapc(char &c,int &wid,unsigned int &code){
	bitset<8> temp;
	for(int t=0;t<8;t++){
		if(code%2==1)temp.set(t,1);
		code=code/2;
	}
	//cout<<temp<<endl;
	string out=temp.to_string().substr(0,wid);
	//cout<<out<<endl;
	hash[c]=out;
	return;
}
void huff::deoutput(){
	char c;
	string all="";
	while(infile.eof()==false){
		infile.read(&c,1);
		//cout<<cts(c)<<" ";
		all=all+cts(c);
	}
	all=all.substr(0,all.size()-8);
	cout<<all<<endl;
	Node* ptr=root;
	for(int t=0;t<all.size();t++){
		if(all[t]=='0'){
			ptr=ptr->left;
		}
		else{
			ptr=ptr->right;
		}
		if(islevea(ptr)){
			outfile<<ptr->c;
			ptr=root;
		}
	}
}
string huff::cts(char &in){
	bitset<8> temp;
	unsigned int i=(unsigned int)in;
	for(int t=0;t<8;t++){
		if(i%2==1)temp.set(t,1);
		i=i/2;
	}
	//cout<<temp<<endl;
	return temp.to_string();
}
















