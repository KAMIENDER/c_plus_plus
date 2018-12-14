#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(vector<int> &in,int a,int b){
	int c=in[a];
	in[a]=in[b];
	in[b]=c;
} 
void tquicksort(vector<int> &in,int bot,int top){
	if(bot>=top)return;
	int now=(bot+top)/2;
	swap(in,now,bot);
	int key=in[bot];
	int last=bot;
	in.
	//vector<double> temp=in;
	for(int t=bot+1;t<=top;t++){//注意是小于等于 
		if(in[t]<key){
			last++;
			swap(in,last,t);
		}
	}
	swap(in,last,bot);
	tquicksort(in,bot,last-1);
	tquicksort(in,last+1,top);
}
void quicksort(vector<int> &in){
	tquicksort(in,0,in.size()-1);
}
int select_kth_smallest(vector<int> v, size_t k){
	quicksort(v);
	return v[k-1];
}

