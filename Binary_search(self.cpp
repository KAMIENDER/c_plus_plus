#include<iostream>
#include<vector>
using namespace std;
template <typename T>
int search(const vector<T> in,T key,int bot,int top){
	if(bot<top){
		int mid=top-(top-bot)/2;
		if(in[mid]>key)return search(in,key,bot,mid-1);
		else return search(in,key,mid,top);
	}
	else{
		if(in[bot]==key)return bot;
		else return -1;
	}
}
int main(){
	cout<<6<<endl;
	vector<int> test;
	test.push_back(1);
	test.push_back(3);
	test.push_back(4);
	test.push_back(6);
	test.push_back(9);
	cout<<search(test,1,0,4)<<endl;
	cout<<search(test,2,0,4)<<endl;
	cout<<search(test,9,0,4)<<endl;
}


