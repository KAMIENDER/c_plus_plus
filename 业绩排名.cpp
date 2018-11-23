#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
bool cmp(pair<string,int> a,pair<string,int> b){
	if(a.second>b.second)return true;
	else return false;
}
vector<pair<int, string> > bonusList(vector<pair<string, int> > v){
	sort(v.begin(),v.end(),cmp);
	int n=0;
	vector<pair<int,string> >out;
	vector<pair<string, int> >::iterator t=v.begin();
	int key=0;
	while(t!=v.end()){
		pair<int,string> temp;
		if(t==v.begin()){
			n++;
			key=(*t).second;
		}
		else{
			if((*t).second==key);
			else{
				n++;
				key=(*t).second;
			}
		}
		temp.second=(*t).first;
		temp.first=n;
		t++;
		out.push_back(temp);
	} 
	return out;
}
int main(){
	vector<pair<string, int> > v;
	v.push_back(pair<string,int>("wang ming", 320));
	v.push_back(pair<string,int>("gao min", 330));
	v.push_back(pair<string,int>("zhang li", 280));
	v.push_back(pair<string,int>("luo yan", 320));
	vector<pair<int, string> > out=bonusList(v);
	vector<pair<int, string> >::iterator t=out.begin();
	while(t!=out.end()){
		cout<<(*t).first<<" "<<(*t).second<<endl;
		t++;
	}
	return 0;
}
