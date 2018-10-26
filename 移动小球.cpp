#include<iostream>
#include<vector>
using namespace std;
void solve();
int main(){
	int n;
	cin>>n;
	for(int t=0;t<n;t++){
		solve();
	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> all;
	vector<int> set;
	for(int t=0;t<n;t++){
		all.push_back(t+1);
		set.push_back(t+1);
	}
	int con;
	cin>>con;
	for(int t=0;t<con;t++){
		int c,from,to;
		
		if(c==1){
			int start=set[from-1];
			int end=set[to-1];
			vector<int>::iterator p=all.begin();
			p=p+end-2;
			all.insert(p,from);
			p=all.begin();
			if(end>start){
			p=p+start-1;
			set[from-1]=end-1;
			for(int t=0;t<all.size();t++){
				if(set[t]>start&&set[t]<end&&t!=from-1)set[t]--;
			}
			}
			if(end<start){
			p=p+start;
			set[from-1]=end;
			for(int t=0;t<all.size();t++){
				if(set[t]>=end&&set[t]<start&&t!=from-1)set[t]++;
			}
			}
			all.erase(p);
			for(int t=0;t<)
		}
		
		if(c==2){
			
		}
		
	}
}
