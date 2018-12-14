#include <iostream>
#include <vector>
#include <string>
//#include <iterator>

using namespace std;

struct Customer {
  string name;
  string phone;
  string address;
};
#include<algorithm>
//#include"Customer.h"
bool cmp(Customer a,Customer b){
	return a.name<b.name;
}
vector<int> accessArray(const vector<Customer> & table){
	vector<int> out;
	vector<Customer> in=table;
	sort(in.begin(),in.end(),cmp);
	for(int t=0;t<in.size();t++){
		int pos;
		for(int i=0;i<in.size();i++){
			if(in[t].name==table[i].name&&in[t].phone==table[i].phone&&in[t].address==table[i].address){
				pos=i;
				break;
			}
		}
		out.push_back(pos);
	}
	return out;
}
int main(){
	Customer a;
	Customer b;
	Customer c;
	Customer d;
	a.name="Wang";
	a.address="address1";
	a.phone="123456";
	b.address="address2";
	b.name="Gao";
	b.phone="23456";
	c.address="address3";
	c.name="Li";
	c.phone="55688";
	d.address="address4";
	d.name="Hao";
	d.phone="56788";
	vector<Customer> all;
	all.push_back(a);
	all.push_back(b);
	all.push_back(c);
	all.push_back(d);
	vector<int> out=accessArray(all);
	for(int t=0;t<4;t++){
		cout<<out[t]<<endl;
	}
}
