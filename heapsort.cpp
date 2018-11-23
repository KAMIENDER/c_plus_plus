#include<iostream>
#include<vector>
using namespace std;
void ajust(vector<int> &in,int low,int high,int key){
	int now=2*low+1;
	while(now<=high){
		if(now<high&&in[now]<in[now+1]){
			now++;
		}
		else if(key>in[now]){
			break;
		}
		in[low]=in[now];
		low=now;
		now=low*2+1;
	}
	in[low]=key;
}

void build(vector<int> &in){
	int top=in.size()/2-1;
	for(int t=top;top>=0;top--){
		ajust(in,top,in.size()-1,in[top]);
	}
}

void heapsort(vector<int> &in){
	build(in);
	for(int t=in.size()-1;t>0;t--){
		int key=in[t];
		in[t]=in[0];
		ajust(in,0,t-1,key);
	}
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
	heapsort(test);
	for(int t=0;t<n;t++){
		cout<<test[t]<<" ";
	}
}
