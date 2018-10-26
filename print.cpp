/*#include <iostream>
#include<string>
using namespace std;


typedef string T;

struct Node {
//  data members
   T data;
   Node *next;
//  constructors
   Node(){ next = NULL;};
   Node(T item, Node *add_on = NULL){
      data = item;
      next = add_on;
   };
};
int print(Node* head){
	Node* now=head;
	while(now!=NULL){
		cout<<now->data<<" ";
		now=now->next;
	}
	cout<<endl;
	return 0;
};
//template<typename T>
Node* insertFront(Node *&head, const T &x){
	Node* now=new Node;
	now->data=x;
	now->next=head;
	head=now;
	return head;
};
Node* foo(){
	Node* head=new Node;
	head->data="Stacks";
	Node* now=new Node;
	now->data="are";
	head->next=now;
	Node* tt=new Node;
	tt->data="lists.";
	now->next=tt;
	tt->next=NULL;
	return head;
}
//template<typename T>
Node* pushBack(Node *&head, const T & x){
	Node *now=new Node;
	Node *bp;
	bp=head;
	if(head!=NULL){
	while(bp->next!=NULL){
		bp=bp->next;
	}
	now->data=x;
	now->next=NULL;
	bp->next=now;
	}
	else{
	head=new Node;
	now->data=x;
	now->next=NULL;
	head=now;
	}
	return head;
};
//template<typename T>
Node* copyList( const Node*  head ){
	Node *ptr=new Node;
	if(head==NULL){
		ptr=NULL;
		return ptr;
	}
	Node *now=new Node;
	Node *now1;
	ptr->data=head->data;
	now=ptr;
	now1=head->next;
	while(now1!=NULL){
			Node *now2=new Node;
			now2->data=now1->data;
			now->next=now2;
			now1=now1->next;
			now=now->next;
	}
	return ptr;
};
int main(){
	Node *head=foo();
	print(head);
	insertFront(head,"ok ");
	pushBack(head,"again");
	print(head);
	Node* now=NULL;
	pushBack(now,"again");
	print(now);
	Node* now1=copyList(head);
	print(now1);
}*/

#include<iostream>
#include<pair>
#include<vector>
#include<string>
using namespace std;
vector<pair<string, int> > frequencies(const vector<string> text, vector<string> keys){
	vector<pair<string,int>> out;
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
	return out;
}
int main(){
	string text;
	string keys;
	text = ("algorithm", "range", "time", "algorithm", "Algorithm", "that", "is", "time");
	keys = ("range", "algorithm", "time", "complexity");
	vector<pair<string,int>> out=frequencies(text,keys);
	for(int t=0;t<out.size();t++){
		cout<<out[t].first<<" "<<out[t].second<<endl;
	}
}

