#include <iostream>

using namespace std;
const int maxSize = 100;
template <typename T>
class Queue {
private:
  T arr[maxSize];
  int top;
  int rear;
  int count;
 public:
 	int start(){
 		return front;
	 }
  Queue(){
  	count=0;
	  top=0;
	  rear=-1; 
  };   // construct an empty queue
  ~Queue(){
  	count=0;
  	top=0;
  	rear=-1;
  };  // destructor
  Queue(const Queue &rhs){
  	count=0;
  	top=0;
  	rear=-1;
  	const T *temp=rhs.arr;
  	for(int t=0;t<rhs.size();t++){
  		push(temp[rhs.top+t]);
	  }
  };
  const Queue& operator=(const Queue &rhs){
  	count=0;
  	top=0;
  	rear=-1;
  	const T *temp=rhs.arr;
  	for(int t=0;t<rhs.size();t++){
  		push(temp[rhs.top+t]);
	  }
	return *this;
  };
  bool empty()const {return count == 0;}
  bool full()const {return count == maxSize;}
  int size()const {return count;}
  bool push(const T &x){
  	if(count==maxSize)return false;
  	rear=(rear==99)?0:rear+1;
  	arr[rear]=x;
  	count++;
  	return true;
  };//enqueue
  bool pop(){
  	if(count==0)return false;
  	count--;
  	top=(top==99)?0:top+1;
  	return true;
  };//dequeue
  const T& front()const{
  	return arr[top];
  };//returns a reference to the front element

};
int main(){
	Queue<int> a;
	for(int t=0;t<3;t++)a.push(t);
	Queue<int> b=a;
	Queue<int> c(a); 
	for(int t=0;t<3;t++){
		cout<<a.front()<<b.front()<<c.front()<<endl;
		cout<<a.size()<<endl<<b.size()<<endl<<c.size()<<endl;
		a.pop();
		b.pop();
		c.pop();
	}
}
