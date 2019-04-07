#include<bits/stdc++.h>
using namespace std;

bool compared_num(bool a,bool b){
	return a==b;
}

class Solution {
private:
	unordered_map<char,char>map{
		{'}','{'},
		{']','['},
		{')','('}
	};
public:
    bool isValid(string s) {
        if(s.empty())return true;
        stack<char>stack;
        for(int i=0;i<s.size();i++){
        	if(s[i]=='('||s[i]=='['||s[i]=='{')
        		stack.push(s[i]);
        	else{
        		if(stack.empty())
        			return false;
        		if(map[s[i]]!=stack.top())
        			return false;
        		stack.pop();
        	}
        }
        return stack.empty()?true:false;
    }
};
void test000(){
	string s="()[]{}";
	bool res=Solution().isValid(s);
	cout<<"你的输出结果是："<<res<<endl;
	bool standerd=true;
	cout<<"正确答案是："<<standerd<<endl;
	if(compared_num(res,standerd))
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