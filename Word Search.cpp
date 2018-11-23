#include<vector>
#include<string>
#include<map>
#include<utility>
#include<stack>
using namespace std;
class Solution {
public:
	vector<pair<int, int> > all;
    bool exist(vector<vector<char>>& board, string word) {
        int high=board.size();
		int len=board.front().size(); 
		return find(board,word,0);
    }
    
    bool find(vector<vector<char>>& board, string word,int n){
    	if(n==word.length())return true;
		for(int t=0;t<board.size();t++){
    		for(int i=0;i<board.front().size();i++){
    			int key=0;
    			
    			if(n==0){
    				if(word[n]==board[t][i]){
    					key=1;	
					}
				}
				
				else{
					if(word[n]==board[t][i]&&n==1){
						if((t+i==all.back().first+all.back().second+1
						&&)||
						t+i==all.back().first+all.back().second-1)
						){
							key=1;
						}
					}
					else if(word[n]==board[t][i]){
						if(pair<int,int>(t,i)!=all.back()&&
						
						){
							key=1;
						}
					}
				}
				
				if(key==1){
					all.push_back(pair<int,int>(t,i));
					if(find(board,word,n+1))return true;
				}
			}
		}
		return false;
	}
    
};
