/*
要写 
*/
#include<iostream>
#include<vector>
using namespace std;
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
void print(vector<double> in){
	for(int t=0;t<in.size();t++){
		cout<<in[t]<<" ";
	}
	cout<<endl;
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



int main(){
	int n;
	cin>>n;
	vector<double> all;
	for(int t=0;t<n;t++){
		double d;
		cin>>d;
		all.push_back(d);
	}
	//insersort(all);
	//shellsort(all);
	//quicksort(all);
	//mergesort(all);
	heapsort(all);
	print(all);
}
