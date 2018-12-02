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
int sequentialsearch(vector<T> const in,T key){
	int t;
	for(t=in.size()-1;t>-1;t--){
		if(in[t]==key)return t;
	}
	return -1;
}


int main(){
	double key;
	vector<double> in;
	createv(in);
	cin>>key;
	sort(in.begin(),in.end());
	cout<<sequentialsearch(in,key)<<endl;
	return 0;
}




















