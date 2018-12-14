#include<iostream>
#include<vector>
using namespace std;
/*
void move(vector<int> &in,int bot,int top){
	if(bot>=top)return;
	for(int t=0;t<=top;t++){
		in[t]=in[t+1];
	}
}*/
void swap(vector<int> &in,int a,int b){
	int c=in[a];
	in[a]=in[b];
	in[b]=c;
} 
void adjust(vector<int> &in,int now,int high){
	if(now==high)return;
	int large=2*now+1;
	int key=in[now];
	while(large<=high){
		if(large<=high&&in[large]>in[large+1]){
			large++;
		}
		if(key<in[large])break;
		in[now]=in[large];
		now=large;
		large=2*now+1;
	}
	in[now]=key;//这里是用now不是large，now才是找到的适合的点 
}
int main(){
	int n;
	cin>>n;
	for(int t=0;t<n;t++){
		int m;
		cin>>m;
		vector<int> test;
		for(int i=0;i<m;i++){
			int c;
			cin>>c;
			test.push_back(c);
		}/*
		int key=test[0];
		move(test,0,m-2);
		test[m-1]=key;*/
		swap(test,0,m-1);
		adjust(test,0,m-2);
		for(int i=0;i<m;i++){
			cout<<test[i]<<" ";
		}
		char c=0x0d;
		cout<<c;
		cout<<endl;
	}
}
