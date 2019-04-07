#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||grid[i][j]!=1)return 0;
        else{
            grid[i][j]=2;//标记已经计算过的区域；
            return 1+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
        }
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0,cur=0;
        if(grid.empty()||grid[0].empty())return res;
        const int rows=grid.size();
        const int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    cur=dfs(grid,i,j);
                    res=max(res,cur);
                }
            }
        }
        return res;
    }
};
void test000(){
	vector<vector<int>> grid=
	{
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
 		{0,0,0,0,0,0,0,1,1,1,0,0,0},
 		{0,1,1,0,1,0,0,0,0,0,0,0,0},
 		{0,1,0,0,1,1,0,0,1,0,1,0,0},
 		{0,1,0,0,1,1,0,0,1,1,1,0,0},
 		{0,0,0,0,0,0,0,0,0,0,1,0,0},
 		{0,0,0,0,0,0,0,1,1,1,0,0,0},
 		{0,0,0,0,0,0,0,1,1,0,0,0,0}
	};
	int res=Solution().maxAreaOfIsland(grid	);
	cout<<res<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}