#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int mid = (nums.size()-1)/2;
        int bot = 0;
        int top = nums.size()-1;
        while(bot<top){
            (nums[mid]<target)?bot=mid+1:top=mid;
            mid = (bot+top)/2;
        }
        //if(target>nums[bot])return bot+1;
        return bot;
    }
	
int main(){
	ifstream in("bianrytest.txt");
	vector<int> test;
	int i;
	while(in>>i){
		test.push_back(i);
	}
	int n;
	cin>>n;
	cout<<searchInsert(test,n);
} 
