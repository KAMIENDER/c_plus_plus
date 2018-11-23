#include<iostream> 
using namespace std;
typedef int Stack_entry;
struct node{
	Stack_entry data;
	node *next;	
};
class Stack {
private:
	int len;
	node *now;
public:
node *start()const{
	return now;
}
// Standard Stack methods
Stack(){
	len=0;
	now=NULL;
};
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
	node *ptr=new node;
	ptr->next=now;
	ptr->data=item;
	now=ptr;
	len++;
};
/*item is pushed into the stack and it becomes the new top element.
*/
void pop(){
	if(len>0){
		node *ptr=now;
		now=now->next;
		delete ptr;
		len--;
	}
};
/*The top item is removed if the stack is not empty.
Otherwise, nothing happens.
*/

 Stack_entry & top() const{
 	if(len>0)return now->data;
 	else{
 		Stack_entry out=-1;
 		return out;
	 }
 };
/* The top element is returned by item if the stack is not empty,
and the stack remains unchanged.
Nothing happens if the stack is empty.
*/
// Safety features
~Stack(){
	if(len==0) return;
	while(now!=NULL){
		node *ptr=now;
		now=now->next;
		delete ptr;
	}
};
Stack(const Stack &original){
	if(original.empty()==0){
		len=original.size();
		node *temp=original.start();
		int t=0;
		node *ptr1=new node;
		while(temp!=NULL){
			t++;
			ptr1->data=temp->data;
			node *ptr2=new node;
			temp=temp->next;
			ptr1->next=ptr2;
			if(t==1)now=ptr1;
			ptr1=ptr1->next;
		}
		ptr1=NULL;
	}
	else{
		len=0;
		now=NULL;
	}
};
void operator =(const Stack &original){
	while(len>0){
		pop();
	}
	if(original.empty()==0){
		len=original.size();
		node *temp=original.start();
		int t=0;
		node *ptr1=new node;
		while(temp!=NULL){
			t++;
			ptr1->data=temp->data;
			node *ptr2=new node;
			temp=temp->next;
			ptr1->next=ptr2;
			if(t==0)now=ptr1;
			ptr1=ptr1->next;
		}
		ptr1=NULL;
	}
	else{
		len=0;
		now=NULL;
	}
};
};


typedef Stack MyStack;
int main(){
	Stack test;
	for(int t=0;t<5;t++){
		test.push(t);
	}
	Stack a=test;
	Stack b(test);
	for(int t=0;t<5;t++){
		cout<<test.top()<<endl;
		cout<<a.top()<<endl;
		cout<<b.top()<<endl;
		test.pop();
		a.pop();
		b.pop();
	}
} 
