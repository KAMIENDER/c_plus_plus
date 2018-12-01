#include<iostream>
#include<vector>
using namespace std;
void swap(vector<double> &in,int a,int b){
	double temp = in[a];
	in[a] = in[b];
	in[b] = temp;
}
void move(vector<double> &in,int bot,int top){
	if(bot>=top)return;
	for(;top>bot;top--){
		in[top]=in[top-1];
	}
}
void insersort(vector<double> &in){
	for(int t=0;t<in.size();t++){
		int i=t;
		double key=in[i];
		while(i>0&&key<in[i-1]){
			i--;
		}
		move(in,i,t);
		in[i]=key;
	}
}
void print(vector<double> in){
	for(int t=0;t<in.size();t++){
		cout<<in[t]<<" ";
	}
	cout<<endl;
}
void shellsort(vector<double> &in){
	int increat=in.size()/2;
	
}

int main(){
	int n;
	cin>>n;
	vector<double> all;
	for(int t=0;t<n;t++){
		double d;
		cin>>d;
		all.push_back(d);
	}
	insersort(all);
	print(all);
}