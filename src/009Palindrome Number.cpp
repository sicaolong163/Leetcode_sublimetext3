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
    bool isPalindrome(int x) {
        string s=to_string(x);
        int left=0,right=s.size()-1;
        while(left<right){
        	if(s[left]!=s[right])
        		return false;
        	left++,right--;
        }
        return true;
    }
};
void test000(){
	bool res=Solution().isPalindrome(121);
	cout<<"你的输出结果是："<<"true"<<endl;
	string standerd="true";
	cout<<"正确答案是："<<standerd<<endl;
	if(compared_string("true",standerd))
		cout<<"你的答案正确,再接再厉"<<endl;
	else 
		cout<<"你的答案错了，检查一下吧！"<<endl;

}

int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}