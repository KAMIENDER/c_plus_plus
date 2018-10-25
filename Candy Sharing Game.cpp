#include<iostream>
#include<vector> 
#include<climits>
using namespace std;
template<typename T>
void cal(vector<T> in);
int main(){
	int in;
	cin>>in;
	while(in!=0){
		vector<int> org;
		for(int t=0;t<in;t++){
			int temp;
			cin>>temp;
			org.push_back(temp);
		}
		cal(org);
		cin>>in;
	}
}
template<typename T>
void cal(vector<T> in){
	int n=in.size();
	int count=0;
	int max=0;
	int min=INT_MAX;
	while(1){
		int max=0;
		int min=INT_MAX;
		count++;
		vector<T> temp;
		for(int t=0;t<n;t++){
			temp.push_back(in[t]/2);
		}
		for(int t=n-2;t>-1;t--){
			in[t]=temp[t]+temp[t+1];
			if(in[t]%2==1)in[t]++;
			max=(max>in[t])?max:in[t];
			min=(min>in[t])?in[t]:min;
		//	cout<<t<<": "<<in[t]<<"   "; 
		}
		int t=n-1;
		in[t]=temp[t]+temp[0];
		if(in[t]%2==1)in[t]++;
		max=(max>in[t])?max:in[t];
		min=(min>in[t])?in[t]:min;
		//cout<<t<<": "<<in[t]<<"   "<<endl; 
		//cout<<max<<"::"<<min<<endl;
		//getchar();
		if(max==min)break;
	}
	cout<<count<<" "<<in[0]<<endl;
	return;
}
