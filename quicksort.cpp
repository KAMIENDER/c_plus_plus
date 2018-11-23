#include<iostream>
#include<vector>
using namespace std;
void quicksort(vector<int> &in,int bot,int top){
	if(bot==top||top<bot)return;
	vector<int> temp=in;
	int key=in[bot];
	int begin=bot;
	int end=top;
	for(int t=bot+1;t<=top;t++){
		key>in[t]?temp[begin++]=in[t]:temp[end--]=in[t];
	}
	temp[begin]=key;
	in=temp;
	quicksort(in,bot,begin-1);
	quicksort(in,end+1,top);	
} 

int main(){
	int n;
	cin>>n;
	vector<int> test;
	for(int t=0;t<n;t++){
		int i;
		cin>>i;
		test.push_back(i);
	}
	quicksort(test,0,n-1);
	for(int t=0;t<n;t++){
		cout<<test.back()<<" ";
		test.pop_back();
	}
}
