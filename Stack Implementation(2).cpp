#include<iostream>
using namespace std;
typedef int Stack_entry;
struct Node{
		Node *before;
		Node *next;
		Stack_entry data;
}; 
class Stack {
private:
	int len;
	Node *now;
	Node *head;
public:
// Standard Stack methods
Stack(){
	len=0;
	now=new Node;
	now->before=NULL;
	now->next=NULL;
	head=NULL;
};
Node *start()const{
	return head;
}
bool empty() const{
	return len==0;
};
/* Returns true if the stack is empty, otherwise, returns false.
*/
int size() const{
	return len;
};
/* Returns the number of elements in the stack.
*/
void push(const Stack_entry &item){
	Node *ptr=new Node;
	ptr->data=item;
	ptr->before=now;
	now->next=ptr;
	now=ptr;
	now->next=NULL;
	len++;
	if(len==1)head=now;
};
/*item is pushed into the stack and it becomes the new top element.
*/
void pop(){
	if(len!=0){
		len--;
		Node *ptr=now;
		now=now->before;
		ptr->before=NULL;
		now->next=NULL;
		delete ptr;
	}
};
/*The top item is removed if the stack is not empty.
Otherwise, nothing happens.
*/
 Stack_entry & top() const{
 	return now->data;
 };
/* The top element is returned by item if the stack is not empty,
and the stack remains unchanged.
Nothing happens if the stack is empty.
*/
// Safety features
~Stack(){
	while(now!=NULL){
		Node *ptr=now;
		if(now)now=now->before;
		delete ptr;
	}
	len=0;
};
Stack(const Stack &original){
	now=new Node;
	now->before=NULL;
	len=0;
	Node *ptr=original.start();
	while(ptr!=NULL){
		push(ptr->data);
		ptr=ptr->next;
	}
};
void operator =(const Stack &original){
	this->~Stack();
	now=new Node;
	len=0;
	now->before=NULL;
	Node *ptr=original.start();
	while(ptr!=NULL){
		push(ptr->data);
		ptr=ptr->next;
	}
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
		cout<<a.top()<<" "<<a.size()<<" "<<a.empty()<<endl;
		cout<<b.top()<<" "<<b.size()<<" "<<b.empty()<<endl;
		cout<<c.top()<<" "<<c.size()<<" "<<c.empty()<<endl;
		a.pop();
		b.pop();
		c.pop();
	}
	cout<<" "<<a.empty()<<endl;
	cout<<" "<<b.empty()<<endl;
	cout<<" "<<c.empty()<<endl;
}
