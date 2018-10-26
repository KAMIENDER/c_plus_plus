#include<iostream>
#include<utility>
#include<vector>
#include<string>
using namespace std;
vector<pair<string, int> > frequencies(const vector<string> text, vector<string> keys){
	vector<pair<string,int> > out;
	for(int t=0;t<keys.size();t++){
		pair<string,int> now;
		now.first=keys[t];
		now.second=0;
		string key=keys[t];
		for(int x=0;x<text.size();x++){
			if(key==text[x]){
				now.second++;
			}
		}
		out.push_back(now);
	}
	for(int t=1;t<out.size();t++){
		int g=t;
		while(out[g].second>=out[g-1].second&&g>0){
			if(out[g].second>out[g-1].second){
				pair<string,int> temp=out[g];
				out[g]=out[g-1];
				out[g-1]=temp;
			}
			else{
				if(out[g].first[0]<out[g-1].first[0]){
				pair<string,int> temp=out[g];
				out[g]=out[g-1];
				out[g-1]=temp;
				}
				else break;
			}
			g--;
		} 
	} 
	return out;
}
int main(){
	vector<string> text;
	vector<string> keys;
	text.push_back("algorithm");
	text.push_back("range");
	text.push_back("time");
	text.push_back("algorithm");
	text.push_back("Algorithm");
	text.push_back("that");
	text.push_back("is");
	text.push_back("time");
	keys.push_back("range");
	keys.push_back("algorithm");
	keys.push_back("time");
	keys.push_back("complexity");
	vector<pair<string,int> > out=frequencies(text,keys);
	for(int t=0;t<out.size();t++){
		cout<<out[t].first<<" "<<out[t].second<<endl;
	}
}
