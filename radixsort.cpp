#include<string>
#include<queue>
#include<list>
#include<iostream>
using namespace std;
template<typename T>
class sortlist:public list<T>{
	public:
		void radixsort();
		void print(){
			auto now=this->begin();
			for(int t=0;t<this->size();t++){
				cout<<*now<<" ";
				now++;
			}
			cout<<endl;
		}
	private:
		void assign(queue<T> *in);
};
int getpos(char in){
	if(in==' ')return 0;
	if(in>='a'&&in<='z')return in-'a'+1;
	if(in>='A'&&in<='Z')return in-'A'+1;
	return 27;
}
template<typename T>
void sortlist<T>::radixsort(){
	int size=3;
	queue<T> all[28];
	for(int t=size-1;t>-1;t--){//关键字从后往前 ，最后一次肯定是拍第一位 
		while(this->empty()==false){
			T now=this->front();
			this->pop_front();
			int pos=getpos(now[t]);
			all[pos].push(now);
		}
		assign(all);
	}
}
template<typename T>
void sortlist<T>::assign(queue<T> *in){
	for(int t=0;t<28;t++){
		while(in[t].empty()==false){//把对应每个字母下标的单词取出，赋值给本来的vector 
			this->push_back(in[t].front());
			in[t].pop();
		}
	}
}
int main(){
	sortlist<string> test;
	int n;
	string temp;
	cin>>n;
	for(int t=0;t<n;t++){
		cin>>temp;
		test.push_back(temp);
	}
	test.print();
	test.radixsort();
	test.print();
	return 0; 
}
