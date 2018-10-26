#include<iostream>
#include<string>
using namespace std;
void sol(int now,string in,string create){
	if(now==in.length()){
		cout<<create<<endl;
		return;
	}
	int key=1;
	for(int t=0;t<in.length();t++){
		for(int x=0;x<create.length();x++){
			if(in[t]==create[x])key=0;
		}
		if(key){
			create.push_back(in[t]);
			sol(now+1,in,create);
			create.erase(create.length()-1);
		}
		key=1;
	}
	return ;
};
int main(){
	int n;
	cin>>n;
	for(int t=0;t<n;t++){
		string in;
		cin>>in;
		sol(0,in,"");
	}
} 
