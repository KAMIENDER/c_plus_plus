#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
	string id;
	string day;
	string others;
	int mo;
};

struct Node2{
	string id;
	int mo;
};

bool cmp(Node a,Node b){
	if(a.id==b.id)return a.day<b.day;
	else return a.id<b.id;
}

void getinfo(ifstream &in,vector<Node> &info,ofstream &out){
	string line;
	getline(in,line);
	while(getline(in,line)){
		Node temp;
		int t=0;
		temp.id=line.substr(0,10);
		temp.day=line.substr(11,10);
		if(line[22]=='w'){
			temp.others=line.substr(22,8);
			temp.mo=stoi(line.substr(31));
		}
		if(line[22]=='d'){
			temp.others=line.substr(22,7);
			temp.mo=stoi(line.substr(30));
		}
		info.push_back(temp);
	}
	sort(info.begin(),info.end(),cmp);
}

void output(ofstream &out,vector<Node> &info,vector<Node2> &all){
	int i=0;
	for(int t=0;t<info.size();t++){
		if(all[i].id!=info[t].id){
			out<<"id£º"<<all[i].id<<" "<<"sum: "<<all[i].mo<<endl<<endl;
			i++;
		}
		out<<info[t].id<<" "<<info[t].day<<" "<<info[t].others<<" "<<info[t].mo<<endl;
	}
	out<<"id£º"<<all[i].id<<" "<<"sum: "<<all[i].mo<<endl;
}

vector<Node2> output1(vector<Node> &info){
	vector<Node2> all;
	Node2 temp2;
	temp2.mo=0;
	for(int t=0;t<info.size();t++){
		if(t==0||info[t].id==info[t-1].id){
			if(info[t].others[0]=='w')temp2.mo=temp2.mo-info[t].mo;
			else temp2.mo=temp2.mo+info[t].mo;
		}
		else{
			temp2.id=info[t-1].id;
			all.push_back(temp2);
			temp2.mo=0;
			if(info[t].others[0]=='w')temp2.mo=temp2.mo-info[t].mo;
			else temp2.mo=temp2.mo+info[t].mo;
			if(t==info.size()-1){
				temp2.id=info[t].id;
				all.push_back(temp2);
			}
		}
	}
	return all; 
} 

int main(){
	ifstream in("ATM1log201810.txt");
	ofstream out("out.txt");
	if(!in.is_open()){
		cout<<"can't open"<<endl;
		return 0;
	}
	vector<Node> info;
	getinfo(in,info,out);
	vector<Node2> all=output1(info);
	output(out,info,all);
}
