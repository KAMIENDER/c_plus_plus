#include<iostream>
#include<map>
#include"md5.h"
using namespace std;
int main(){
	int n;
	cin>>n;
	map<string,string> all;
	for(int t=0;t<n;t++){
		string name;
		string md5;
		cin>>name;
		cin>>md5;
		all[name]=md5;
	}
}
