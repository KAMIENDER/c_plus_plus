#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int> &in,int a,int b){
	int c=in[a];
	in[a]=in[b];
	in[b]=c;
}
void mergesort(vector<int> &in,int bot,int top){
	if(bot==top)return;
	if(top==bot+1){
		if(in[bot]>in[top])swap(in,bot,top);
		return;
	}
	int mid=bot+(top-bot)/2;
	mergesort(in,bot,mid);
	mergesort(in,mid+1,top);
	vector<int> temp=in;
	int low=bot;
	int high=mid+1;
	int t=bot;
	while(low<=mid&&high<=top){
		in[t++]=(temp[low]<temp[high])?temp[low++]:temp[high++];
	}
	while(low<=mid)in[t++]=temp[low++];
	while(high<=top)in[t++]=temp[high++]; 
}
int main(){
	int n;
	cin>>n;
	vector<int> all;
	for(int t=0;t<n;t++){
		int a;
		cin>>a;
		all.push_back(a);
	}
	mergesort(all,0,n-1);
	for(int t=0;t<n;t++){
		cout<<all[t]<<" ";
	}
}
