/*
	给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0)return res;
        dfs("",n,n);
        return res;
    }
 private:
	vector<string>res;
	void dfs(  const string &cur,int left,int right){
		if(0==right&&left==0){
			cout<<cur<<endl;
			res.push_back(cur);
			return ;
		}
		if(left>0)dfs(cur+'(',left-1,right);
		if(right>left)dfs(cur+')',left,right-1);
		return ;
	}
};
void test000(){
	vector<string>res=Solution().generateParenthesis(3);
	cout<<"answer:"<<endl;
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
	cout<<endl;
}

int main()
{
	test000();
	cout<<"---------华丽的分割线----------"<<endl;
	cout<<"hello world"<<endl;
	return 0;
}