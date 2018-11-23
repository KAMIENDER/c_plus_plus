#include<iostream>
using namespace std;
template <typename T> class Queue {
private:
 //using a static array of size 100.   
	T all[100];
	int len;
	int begin;
	int end;
public:
	int beg()const{
		return begin;
	}
	T *start(){
		return all;
	}
     Queue(){
	 	len=0;
	 	begin=0;
	 	end=-1;
	 };   // construct an empty queue
      ~Queue(){
      	len=0;
	  };  // destructor
      Queue(const Queue &rhs){
      	const T *temp=rhs.all;
      	len=0;
      	if(rhs.size()==0){
      		begin=0;
      		end=-1;
		  }
		else{
			begin=0;
      		end=-1;
			for(int t=0;t<rhs.size();t++){
				push(temp[t+rhs.beg()]);
			}
		}
	  };
      const Queue & operator=(const Queue &rhs){
	  	const T *temp=rhs.all;
	  	len=0;
      	if(len==0){
      		begin=0;
      		end=-1;
		  }
		else{
			begin=0;
      		end=-1;
			for(int t=0;t<rhs.size();t++){
				push(temp[t+rhs.beg()]);
			}
		}
		return *this;
	  };
      bool empty()const{
	  	return len==0;
	  };
      bool full()const{
	  	return len==100;
	  };
      int size()const{
	  	return len;
	  };
      bool push(const T &x){
      	if(full()==true)return false;
	  	end=(end==99)?0:end+1;
	  	len++;
	  	all[end]=x;
	  	return true;
	  };//enqueue
      bool pop(){
	  	if(len==0)return false;
	  	len--;
	  	begin=(begin==99)?0:begin+1;
	  	return true;
	  };//dequeue
      const T & front()const{
	  	return all[begin];
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
