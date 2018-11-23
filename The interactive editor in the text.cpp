#include<string>
#include<iostream>
#include<fstream>
#include<list>
using namespace std;
class Editor : public list<string> {
private:
	ifstream *in;
	ofstream *out;
	list<string>::iterator now;
	size_t linenum;
	size_t nownum;
public:
	Editor(ifstream &file_in, ofstream &file_out) {
		in = &file_in;
		linenum = 0;
		out = &file_out;
		string word;
		while (getline((*in),word)) {
			push_back(word);
			//cout << word << endl;
			linenum++;
		}
		now=begin();
		nownum=1;
	};
	size_t number_of_lines()const { return linenum; };
	size_t number_of_characters()const {
		int num=0;
		for (list<string>::const_iterator t = begin(); t != end(); t++) {
			num = num+(*t).length();
		}
		return num;
	};
	size_t current_line(){
		/*
		list<string>::iterator temp=begin();
		nownum =1;
		while(temp!=now){
			nownum++;
		}*/
		return nownum;
	};//return current line number
	bool next_line(){
		if(nownum+1>linenum)return false;
		else{
			now++;
			nownum++;
			return true;
		}
	};//goto next line, returns true if successfule, otherwise returns false.
	bool previous_line(){
		if(nownum-1==0)return false;
		else{
			now--;
			nownum--;
			return true;
		}
	};//goto previous line, returns true if successfule, otherwise returns false.
	bool goto_line(size_t line_number){
		if(0<line_number&&line_number<=linenum){
			while(nownum>line_number){
				nownum--;
				now--;
			}
			while(nownum<line_number){
				nownum++;
				now++;
			}
			return true;
		}
		return false;
	};//goto the specified line(lines are numbered 1,2,3,...), returns true if successfule, otherwise returns false.
	bool insert_line(string to_be_inserted){
		linenum++;
		insert(now,to_be_inserted);
		return true; 
	};//insert a line before the current line, returns true if successfule, otherwise returns false.
	bool remove_line(size_t line_number){
		if(line_number==0||line_number>linenum)return false;
		size_t t=1;
		linenum--;
		list<string>::iterator temp=begin();
		while(t!=line_number){
			t++;
			temp++;
		}
		erase(temp);
		return true;
	};//remove the specified line, returns true if successfule, otherwise returns false.
	bool replace(string substr1, string substr2){
		int a=(*now).find(substr1);
		while(a!=-1){
			(*now).erase(a,substr1.length());
			(*now).insert(a,substr2);
			a=(*now).find(substr1);
		}
		return true;
	};//substitute all occurences of substr1 by substr2 in current line, returns true if successfule, otherwise returns false.
	bool substitute(string substr1, string substr2){
		list<string>::iterator temp=begin();
		while(temp!=end()){
			int a=(*temp).find(substr1);
			while(a!=-1){
				(*temp).erase(a,substr1.length());
				(*temp).insert(a,substr2);
				a=(*temp).find(substr1);
			}
			temp++;
		}
		return true;
	};//substitue al l substr1 by substr2), returns true if successfule, otherwise returns false.
	void write_file(){
		list<string>::iterator temp=begin();
		while(temp!=end()){
			(*out) << (*temp)<<endl;
			temp++;
		}
	};//write out to current file stream.
};
void print(Editor in){
	for(list<string>::iterator temp=in.begin();temp!=in.end();temp++){
		cout<<*temp<<endl;
	}
} 
void printc(Editor in,int line){
	int t=1;
	for(list<string>::iterator temp=in.begin();temp!=in.end();temp++){
		if(t==line){
			cout<<*temp<<endl;
			break;
		}
		t++;
	}
}
int main() {
	ifstream in;
	ofstream out;
	out.open("E:/test_file/tot.txt");
	in.open("E:/test_file/tet.txt");
	Editor test(in, out);
	cout << test.size() << endl;
	cout<<test.number_of_characters()<<endl;
	cout<<test.current_line()<<endl;
	printc(test,test.current_line());
	test.next_line();
	cout<<test.current_line()<<endl;
	printc(test,test.current_line());
	test.previous_line();
	cout<<test.current_line()<<endl;
	printc(test,test.current_line());
	test.goto_line(1);
	cout<<test.current_line()<<endl;
	printc(test,test.current_line());
	print(test);
	test.insert_line("this is a poem of Taiger");
	cout<<test.number_of_lines()<<endl;
	print(test);
	test.remove_line(3);
	cout<<test.number_of_lines()<<endl;
	print(test);
	test.replace("a","bb");
	print(test);
	test.substitute("a","bb");
	print(test); 
	test.write_file();
	in.close();
	out.close();
	return 0;
}
