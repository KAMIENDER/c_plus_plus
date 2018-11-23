#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
pair<double, int> Q1(vector<double> v){
	sort(v.begin(),v.end());
	int len=v.size();
	int op=int(len*0.25);
	pair<double, int> out(v.at(op),op);
	return out; 
}
int main(){
	vector<double> in;
	in.push_back(1);
	in.push_back(2);
	in.push_back(3);
	in.push_back(2);
	in.push_back(3);
	in.push_back(2);
	in.push_back(4);
	pair<double, int> out=Q1(in);
	cout<<out.first<<" "<<out.second<<endl;
	return 0;
}

 
