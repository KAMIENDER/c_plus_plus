/*
要写 
*/
#include<iostream>
#include<vector>
using namespace std;
template <typename Node_entry>struct Node {
//  data members
   Node_entry entry;
   Node *next;
//  constructors
   Node(){next = NULL;};
   Node(Node_entry item, Node *add_on = NULL){entry = item; next = add_on;};
};
void print(vector<double> in){
	for(int t=0;t<in.size();t++){
		cout<<in[t]<<" ";
	}
	cout<<endl;
}
template<typename T>
void printl(Node<T>* head){
	while(head!=NULL){
		cout<<head->entry<<" ";
		head=head->next;
	}
	cout<<endl;
}
void createvector(vector<double> &out){
	int n;
	cin>>n;
	for(int t=0;t<n;t++){
		double c;
		cin>>c;
		out.push_back(c);
		//print(out);
	} 
	//return out;
}
template<typename T>
Node<T>* createlist(){
	int n;
	cin>>n;
	Node<T>* head=new Node<T>;
	Node<T>* now=head;
	for(int t=0;t<n;t++){
		double c;
		cin>>c;
		now->entry=c;
		if(t<n-1){
			now->next=new Node<T>;
			now=now->next;
		}
	}
	return head;
}
void swap(vector<double> &in,int a,int b){
	double temp = in[a];
	in[a] = in[b];
	in[b] = temp;
}
void move(vector<double> &in,int bot,int top){
	if(bot>=top)return;
	for(;top>bot;top--){
		in[top]=in[top-1];
	}
}
void insersort(vector<double> &in){
	for(int t=0;t<in.size();t++){
		int i=t;
		double key=in[i];
		while(i>0&&key<in[i-1]){
			i--;
		}
		move(in,i,t);
		in[i]=key;
	}
}
void shellsort(vector<double> &in){
	int increat=in.size()/2;
	for(;increat>0;increat=increat/3+1){
		for(int t=0;t<in.size();t=t+increat){
			int j=t;
			while(j>0&&in[j-increat]>in[j]){
				swap(in,j,j-increat);
				j=j-increat;
			}
		}
		if(increat==1)break;
	} 
}
void tquicksort(vector<double> &in,int bot,int top){
	if(bot>=top)return;
	int now=(bot+top)/2;
	swap(in,now,bot);
	int key=in[bot];
	int last=bot;
	//vector<double> temp=in;
	for(int t=bot+1;t<=top;t++){//注意是小于等于 
		if(in[t]<key){
			last++;
			swap(in,last,t);
		}
	}
	swap(in,last,bot);
	tquicksort(in,bot,last-1);
	tquicksort(in,last+1,top);
}
void quicksort(vector<double> &in){
	tquicksort(in,0,in.size()-1);
}
void tmergesortvd(vector<double> &in,int bot,int top){
	if(bot==top-1){
		if(in[bot]>in[top])swap(in,bot,top);
		return;
	}
	if(bot>=top)return;
	int mid=bot+(top-bot)/2;
	tmergesortvd(in,bot,mid);
	tmergesortvd(in,mid+1,top);
	int mark=mid+1;//注意这里的mark是上面分开排序的后半部分的第一个元素下标 
	int down=bot;
	vector<double> temp=in;
	while(bot<=mid&&mark<=top){
		in[down++]=(temp[bot]<temp[mark])?temp[bot++]:temp[mark++];//注意谁小选谁 
	}
	while(bot<=mid){
		in[down++]=temp[bot++]; 
	}
	while(mark<=top){
		in[down++]=temp[mark++];
	} 
	return;
}
void mergesort(vector<double> &in){
	tmergesortvd(in,0,in.size()-1);
}
void adjust(vector<double> &in,int now,int high){
	int large=2*now+1;
	int key=in[now];
	while(large<high){
		if(large+1<high&&in[large]<in[large+1]){
			large++;
		}
		if(key>in[large])break;
		in[now]=in[large];
		now=large;
		large=2*now+1;
	}
	in[now]=key;//这里是用now不是large，now才是找到的适合的点 
}
void build(vector<double> &in){
	int now=in.size()/2-1;
	for(;now>-1;now--){
		adjust(in,now,in.size());
	}
	//print(in);
}
void heapsort(vector<double> &in){
	build(in);
	for(int t=in.size();t>0;t--){
		int temp=in[0];
		in[0]=in[t-1];
		in[t-1]=temp;
		adjust(in,0,t-1);
	}
	return;
}
void insertsortb(vector<double> &in){
	for(int t=1;t<in.size();t++){
		if(in[t]<in[t-1]){
			int key=in[t];
			int i=t;
			do{
				in[i]=in[i-1];
				i--;
			}while(i>0&&key<in[i-1]);
			in[i]=key;
		}
	}
}
template<typename T>
void insertsortbn(Node<T>* head){
	if(head==NULL||head->next==NULL)return;
	Node<T>* sorted=head;
	Node<T>* sort;
	while(sorted->next!=NULL){
		sort=sorted->next;
		if(sort->entry>=sorted->entry){
			sorted=sorted->next;
			continue;
		}
		Node<T>* now=head;
		if(now->entry>sort->entry){
			sorted->next=sort->next;
			sort->next=head;
			head=sort;
			continue;
		}
		now=now->next;
		Node<T>* pre=head;
		while(now->entry<=sort->entry){
			pre=pre->next;
			now=now->next;
		}
		sorted->next=sort->next;
		sort->next=now;
		pre->next=sort;
	}
}
void selectionsort(vector<double> &in){
	for(int t=in.size()-1;t>0;t--){
		int max=in[0];
		int key=0;
		for(int i=0;i<=t;i++){
			key=(max<in[i])?i:key;
			max=(max<in[i])?in[i]:max;
		}
		swap(in,key,t);
	}
}
int main(){
	vector<double> all;
	createvector(all);
	//Node<double>* head=createlist<double>();
	//insersort(all);
	//shellsort(all);
	//quicksort(all);
	//mergesort(all);
	//heapsort(all);
	//insertsortb(all);
	selectionsort(all);
	print(all);
	//insertsortbn(head);
	//printl(head);
}
