/*
	给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
#include<bits/stdc++.h>
using namespace std;
bool compared_string(string s1,string s2){
	return s1==s2;
}

bool compared_string(vector<string> a,vector<string> b){
	return a==b;
}
class Solution {
private:
	unordered_map<char ,string>map={
		 {'0'," "},{'1',""},{'2',"abc"},
		 {'3',"def"},{'4',"ghi"},{'5',"jkl"},
		 {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},
		 {'9',"wxyz"}
	};
	vector<string>res;
	void dfs(string &digits,int index,const string &cur){
		if(index==digits.size()){
			res.push_back(cur);
			return ;
		}
		char c=digits[index];
		string tmp=map[c];
		for(int i=0;i<tmp.size();i++){
			dfs(digits,index+1,cur+tmp[i]);
		}
		return ;
	}
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return res;
        string tmp;
        dfs(digits,0,tmp);
        return res;
    }
};
void print(vector<string>&str){
	for(auto i:str){
		cout<<i<<endl;
	}
}
void test000(){
	string digits="23";
	vector<string>res=Solution().letterCombinations(digits);
	cout<<"你的输出结果是：";
	// string standerd="PINALSIGYAHRPI";
	print(res);
	vector<string >standerd={"ad","ae","af","bd","be","bf","cd","ce","cf"};
	cout<<"正确答案是：";
	print(standerd);
	if(compared_string(res,standerd))
		cout<<"your answer is right,nice  job~~~~~come on~~~~~~~ "<<endl;
	else 
		cout<<"your answer is wrong ，is a bad thing !!!!!please check it!!!!!!!!!!!!! "<<endl;

}

int main(){
	test000();
	cout<<"---------华丽的分割线----------"<<endl;
	cout<<"hello world"<<endl;
	return 0;
}