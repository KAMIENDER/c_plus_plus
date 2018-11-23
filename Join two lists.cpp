#include<iostream>
#include<algorithm> 
#include<list>
using namespace std;
list<int> join(const  list<int> &a, const list<int> &b)
{
	list<int> temp1=a;
	list<int> temp2=b;
	temp1.sort();
	temp2.sort();
	list<int> out;
	list<int>::const_iterator aa=temp1.begin();
	list<int>::const_iterator bb=temp2.begin();
	while(aa!=temp1.end()&&bb!=temp2.end()){
		if(*aa==*bb){
			out.push_back(*aa);
			aa++;
			bb++;
		}
		else if(*aa>*bb){
			bb++;
		}
		else aa++;
	}
	out.erase(unique(out.begin(),out.end()),out.end());
	return out;
}
int main(){
	list<int> a;
	list<int> b;
	a.push_back(3);
	a.push_back(4);
	a.push_back(3);
	a.push_back(5);
	b.push_back(2);
	b.push_back(3);
	b.push_back(2);
	b.push_back(12);
	b.push_back(4);
	b.push_back(4);
	list<int> out=join(a,b);
	list<int>::iterator aa=out.begin();
	while(aa!=out.end()){
		cout<<*aa<<endl;
		aa++;
	}
}
