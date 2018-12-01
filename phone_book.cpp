#include<map>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void openfile(ifstream &in,map<string,string> &book){
	string line;
	getline(in,line);
	while(getline(in,line)&&(line[0]<'0'||line[0]>'9')){
		string name="";
		int t=0;
		char i=line[t];
		while(i!=','){
			name=name+i;
			i=line[++t];
		}
		string num=line.substr(t+1);
		book[name]=num;
	}
}
void findself(ifstream &in,ofstream &out,map<string,string> &book){
	string line;
	while(in>>line){
		if(book.find(line)==book.end())out<<line<<":none"<<endl;
		else out<<line<<":"<<book[line]<<endl;
	}
}
int main(){
	ifstream in("phonebook10000.txt");
	ofstream out("out3.txt");
	map<string,string> book;
	openfile(in,book);
	findself(in,out,book);
	return 0; 
}
