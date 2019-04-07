#include<bits/stdc++.h>
using namespace std;
class Solution_dfs{
private:
    int rows,res=0;
    vector<bool>visited;
    void dfs(vector<vector<int>>& M,int i){
        for(int j=0;j<rows;j++){
            if(M[i][j]==1&&!visited[j]){
                visited[j]=true;
                dfs(M,j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
         rows=M.size();
        visited=vector<bool>(rows,false);
        for(int i=0;i<M.size();i++){
            if(!visited[i]){
                dfs(M,i);
                res++;
            }
        }
        return res;
    }
};
class Solution_unifind {
private:
    vector<int>pre;
    int n,res=0;
    int find_root(int x){//查找根节点；
        int root=x;
        while(pre[root]!=root)
            root=pre[root];
        return root;
    }
    void combine(int x,int y){//将两个结点合并到一棵树上；
        int root_x=find_root(x);
        int root_y=find_root(y);
        if(root_x!=root_y){
            pre[root_x]=root_y;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        n=M.size();
        pre=vector<int>(n,0);
        isRoot=vector<bool>(n,false);
        for(int i=0;i<n;i++)
            pre[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]==1)
                    combine(i,j);
            }
        } 
        for(int i=0;i<n;i++){
            if(find_root(i)==i)
                res++;
        }
        return res;
    }
};
void test000(){
	vector<vector<int>> M=
	{
		{1,1,0},
		{1,1,0},
		{0,0,1}
	};
	int res_dfs=Solution_dfs().findCircleNum(M);
	cout<<res_dfs<<endl;
	int res_uni=Solution_unifind().findCircleNum(M);
	cout<<res_uni<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}