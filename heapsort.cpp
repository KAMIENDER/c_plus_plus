#include<iostream>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
void ajust(vector<int> &in,int low,int high,int key){
	int now=2*low+1;
	while(now<=high){
		if(now<high&&in[now]<in[now+1]){
			now++;
		}
		if(key>in[now]){
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

void test(){
	int size=1000;//测试vector的大小 
	int max=10000;//测试数据的范围 
	vector<int> test;
	for(int t=0;t<size;t++){
		srand(time(0));
		int i=rand()%max;
		test.push_back(i);
	}
	vector<int> t2=test;
	sort(test.begin(),test.end());
	heapsort(t2);
	for(int t=0;t<test.size();t++){
		if(test[t]!=t2[t]){
			cout<<"error"<<endl;//失败返回 
			return;
		}
	}
	cout<<"ok"<<endl;
	return ;
}

int main(){
	/*
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
	}*/
	test();
}


