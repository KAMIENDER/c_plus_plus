#include<iostream>
#include<vector>
#include<list>
using namespace std;
typedef int Comparable;

Comparable find_median(const list<Comparable> &l1, const list<Comparable> &l2)
{
//insert here
	auto i = l1.begin();
	auto j = l2.begin();
	int mid = (l1.size()+l2.size()-1)/2+1;  
	int k=0; //k is the index of the next to be merged element
	Comparable end;
	while(k<mid){
		if(l1.size()==0)break;
		if(l2.size()==0)break;
		k++;
		if(*i<*j){
			end=*i;
			i++;
		}
		else{
			end=*j;
			j++;
		}
		if(i==l1.end()||j==l2.end())break;
	}
	while(i!=l1.end()&&k<mid){
		k++;
		end=*i;
		i++;
	}
	while(j!=l2.end()&&k<mid){
		k++;
		end=*j;
		j++;
	}
	if(k<mid){
		if(*i<*j){
			end=*i;
		}
		else end=*j;
	}
	return end;
};
int main(){
	int n;
	list<Comparable> l1;
	cin>>n;
	for(int t=0;t<n;t++){
		Comparable c;
		cin>>c;
		l1.push_back(c);
	}
	list<Comparable> l2;
	cin>>n;
	for(int t=0;t<n;t++){
		Comparable c;
		cin>>c;
		l2.push_back(c);
	}
	cout<<find_median(l1,l2);
	return 0;
}
