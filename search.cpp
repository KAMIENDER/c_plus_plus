#include<iostream>
#include<vector>
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

int main(){
	vector<double> in;
	createv(in);
	printv(in);
	return 0;
}




















