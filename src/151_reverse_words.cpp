#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string &s) {
        istringstream is(s);
        string temp;
        is>>s;//将第一个单词存入到s；
        while(is>>temp) s =temp +" " +s;
        if(!s.empty() && s[0] == ' ') s = "";
        return s;
    }
};
void test000(){
	string s="the sky is blue";
	string res=Solution().reverseWords(s);
	cout<<res<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}