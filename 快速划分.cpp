#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int> &in,int a,int b){
	int c=in[a];
	in[a]=in[b];
	in[b]=c;
} 
void partition(vector<int> &in,int bot,int top){
	if(bot>=top)return;
	int key=in[bot];
	int last=bot;
	//vector<double> temp=in;
	for(int t=bot+1;t<=top;t++){//注意是小于等于 
		if(in[t]<key){
			last++;
			swap(in,last,t);
		}
	}
	swap(in,last,bot);
}
int main(){
	int n;
	cin>>n;
	vector<int> all;
	for(int t=0;t<n;t++){
		int c;
		cin>>c;
		all.push_back(c);
	}
	partition(all,0,n-1);
	int m;
	cin>>m;
	for(int t=0;t<m;t++){
		vector<int> test;
		for(int i=0;i<n;i++){
			int c;
			cin>>c;
			test.push_back(c);
		}
		if(test==all)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
