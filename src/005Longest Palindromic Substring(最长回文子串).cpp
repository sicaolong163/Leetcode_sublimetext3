/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	int n=s.size();
        if(s.empty())return res;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int max_len=0;
        for(int i=0;i<s.size();i++)
        	dp[i][i]=true;
        for(int i=s.size()-1;i>=0;i--){
        	for(int j=i;j<s.size();j++){
        		if((s[i]==s[j])&&(i-j<2||dp[i+1][j-1])){
        			dp[i][j]=true;
        			if(max_len<j-i+1){
        				max_len=j-i+1;
        				res=s.substr(i,max_len);
        			}
        		}
        		
        	}
        }
        return res;
    }
   private:
   	string res;
};
void test005(){
	string s="cbbd";
	string res=Solution().longestPalindrome(s);
	cout<<res<<endl;
}
int main(){
	test005();
	cout<<"hello world"<<endl;
	return 0;
}