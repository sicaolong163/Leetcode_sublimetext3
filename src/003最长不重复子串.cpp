#include<bits/stdc++.h>
using namespace std;

/*
	给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)return 0;
        int res=0;
        int left=0,right=-1;//滑动窗口；
        vector<int>dict(128);//集合或者是字典用来记录滑动窗口内的字母是否出现；
        while(left<n){
        	if(right+1<n&&dict[s[right+1]]==0){
        		dict[s[++right]]++;
        	}else{
        		--dict[s[left++]];
        	}
        	res=max(res,right-left+1);//更新res
        }
        return res;
    }
};
void test003(){
	string s="abcabcbb";
	int res=Solution().lengthOfLongestSubstring(s);
	cout<<res<<endl;
}
int main(){
	test003();
	// cout<<"hello world"<<endl;
	return 0;
}