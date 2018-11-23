#include<stack>
#include<iostream>
using namespace std;
typedef int Stack_entry;
class Stack {
private:
	Stack_entry *all;
	int now;
	int max;	
public:
// Standard Stack methods
Stack(){
	all=new Stack_entry[1000];
	now=0;
	max=1000;
};
bool empty() const{
	return now==0;
};
Stack_entry *start()const{
	return all;
}
/* Returns true if the stack is empty, otherwise, returns false.
*/
int size() const{
	return now;
};
/* Returns the number of elements in the stack.
*/
void push(const Stack_entry &item){
	if(now<max)all[now++]=item;
};
/*item is pushed into the stack and it becomes the new top element.
*/
void pop(){
	if(now>0)now--;
};
/*The top item is removed if the stack is not empty.
Otherwise, nothing happens.
*/

 Stack_entry & top() const{
 	if(now>0){
 		return all[now-1];
	 }
 };
/* The top element is returned by item if the stack is not empty,
and the stack remains unchanged.
Nothing happens if the stack is empty.
*/
// Safety features
~Stack(){
	delete all;
	now=0;
};
Stack(const Stack &original){
	all=new Stack_entry[1000];
	now=original.size();
	Stack_entry *in=original.start();
	for(int t=0;t<now;t++){
		all[t]=in[t];
	}
};
void operator =(const Stack &original){
	all=new Stack_entry[1000];
	now=original.size();
	Stack_entry *in=original.start();
	for(int t=0;t<now;t++)all[t]=in[t];
};
};


typedef Stack MyStack;
int main(){
	Stack a;
	for(int t=0;t<3;t++){
		a.push(t);
	}
	Stack b(a);
	Stack c=a;
	for(int t=0;t<3;t++){
		cout<<a.top()<<endl;
		cout<<b.top()<<endl;
		cout<<c.top()<<endl;
		a.pop();
		b.pop();
		c.pop();
	}
}
