#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T>
void createv(vector<T> &out){
	int n;
	cin>>n;
	for(int t=0;t<n;t++){
		T c;
		cin>>c;
		out.push_back(c);
	}
}
template<typename T>
void printv(const vector<T> &in){
	for(int t=0;t<in.size();t++){
		cout<<in[t]<<" ";
	}
	cout<<endl;
}
template<typename T>
int sequentialsearch(vector<T> const &in,T key){
	int t;
	for(t=in.size()-1;t>-1;t--){
		if(in[t]==key)return t;
	}
	return -1;
}
template<typename T>
int binarysearchrf(vector<T> const &in,int bot,int top,T key){
	if(bot==top){
		if(in[bot]==key)return bot;
		return -1;
	}
	int mid=bot+(top-bot)/2;
	if(in[mid]<key)return binarysearchrf(in,mid+1,top,key);
	return binarysearchrf(in,bot,mid,key);
}
template<typename T>
int binarysearch(vector<T> const &in,T key){
	return binarysearchrf(in,0,in.size()-1,key);
}

int main(){
	double key;
	vector<double> in;
	createv(in);
	cin>>key;
	sort(in.begin(),in.end());
	//cout<<sequentialsearch(in,key)<<endl;
	cout<<binarysearch(in,key)<<endl;
	return 0;
}




















