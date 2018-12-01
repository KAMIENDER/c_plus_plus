#include<iostream>
#include<vector>
#include<fstream> 
using namespace std;
void swap(vector<int> &in,int a,int b){
	int c=in[a];
	in[a]=in[b];
	in[b]=c;
}
void onepivotion(vector<int> &in,int low,int high){
	int key;
	int last;
	//swap(in,low,(low+high)/2);
	key=in[low];
	for(int t=low+1;t<=high;t++){
		if(in[t]<key){
			last++;
			swap(in,last,t);
		}
	}
	swap(in,low,last);
}
int main(){
	ifstream test("onequick.txt");
	vector<int> all;
	int i;
	while(test>>i){

		all.push_back(i);
	}
	onepivotion(all,0,all.size()-1);
	for(int t=0;t<all.size();t++){
		cout<<all[t]<<" ";
	}
	return 0;
} 
