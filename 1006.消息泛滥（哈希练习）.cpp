#include<iostream>
#include<vector>
#include<string>
using namespace std;
class table{
	private:
		vector<string> all;
		int max=42001;
		int left;
		int getpos(const string &in){
			int size=in.size();
			int out=0;
			for(int t=0;t<size;t++){
				out=out*4+getnum(in[t]);
			}
			return out%max;
		}
		int getnum(const char &in){
			if(in>='a'&&in<='z')return in-'a'+1;
			if(in>='A'&&in<='Z')return in-'A'+1;
		}
	public:
		int getsize(){
			return left;
		}
		table(){
			all.resize(max);
			for(int t=0;t<max;t++){
				all[t]="0\0";
			}
			left=0;
		}
		void remove(const string &in);
		int find(const string &in);
		void hashing(const string &in);
};
int table::find(const string &in){
	int pos=getpos(in);
	while(all[pos]!="0\0"){
		if(all[pos]==in)return pos;
		else{
			if(pos<max-1)pos++;
			else pos=0;
		}
	}
	return -1;
}
void table::remove(const string &in){
	int pos=this->find(in);
	if(pos==-1)return;
	else{
		left--;
		all[pos]="1\0";
	}
}
void table::hashing(const string &in){
	int pos=getpos(in);
	//cout<<pos<<endl;
	//cout<<all[pos]<<endl;
	//cout<<in<<endl;
	while(all[pos]!=in){
		if(all[pos]=="0\0"||all[pos]=="1\0"){
			left++;
			all[pos]=in;
			return; 
		} 
		else{
			if(pos<max-1)pos++;
			else pos=0;
		}
	}
}
int main(){
	table test;
	int m;
	int n;
	cin>>n;
	cin>>m;
	for(int t=0;t<n;t++){
		string temp;
		cin>>temp;
		test.hashing(temp);
	}
	for(int t=0;t<m;t++){
		string temp;
		cin>>temp;
		test.remove(temp);
	}
	int t;
	cin>>t;
	cout<<test.getsize();
}
