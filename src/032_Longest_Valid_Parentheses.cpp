#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())return 0;
        stack<int>stack;
        int start=-1,res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')stack.push(i);
            else
            {
                if(stack.empty())
                {
                    start=i;
                }
                else
                {
                    stack.pop();//需要弹出栈顶；
                    if(stack.empty())//如果为空；
                    {
                        res=max(res,i-start);
                    }else//如果不为空；
                    {
                        res=max(res,i-stack.top());
                    }
                }
            }
        }
        return res;
    }
};
void test000(){
	string s="()()()";
	int res=Solution().longestValidParentheses(s);
	cout<<res<<endl;
	string s1="()((())";
	int res1=Solution().longestValidParentheses(s1);
	cout<<res1<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}