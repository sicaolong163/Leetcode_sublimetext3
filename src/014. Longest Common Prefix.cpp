/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/
#include<bits/stdc++.h>
using namespace std;
bool compared_string(string s1,string s2){
	return s1==s2;
}
bool compared_num(int a,int b){
	return a==b;
}
bool compared_nums(vector<int> a,vector<int> b){
	return a==b;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.empty())return res;
        res=strs[0];
        for(auto str:strs){
        	while(str.find(res)!=0)
        		res.pop_back();
        }
        return res;
    }
};
void test000(){
	vector<string>strs={"flower","flow","flight"};
	string res=Solution().longestCommonPrefix(strs);
	cout<<"你的输出结果是："<<res<<endl;
	string standerd="fl";
	cout<<"正确答案是："<<standerd<<endl;
	if(compared_string(res,standerd))
		cout<<"你的答案正确,再接再厉"<<endl;
	else 
		cout<<"你的答案错了，检查一下吧！"<<endl;

}

int main(){
	test000();
	cout<<"---------华丽的分割线----------"<<endl;
	cout<<"hello world"<<endl;
	return 0;
}