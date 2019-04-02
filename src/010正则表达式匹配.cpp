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
bool compared_bool(bool a,bool b){
	return a==b;
}
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1=s.length(),n2=p.length();
        if(n1==0&&n2!=0)return false;
        if(n1==0&&n2==0)return true;
        if(n1!=0&&n2==0)return false;
        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n1;i++){
        	for(int j=1;j<=n2;j++){
        		if(p[j-1]=='*'){//判断 某一位是不是*号；
        			dp[i][j]=dp[i][j-2]||(i>0&&(s[i-1]==p[j-2]||p[j-2]=='.')&&dp[i-1][j]);
        		}
        		else{
        			dp[i][j]=(i>0&&(s[i-1]==p[j-1]||p[j-1]=='.'))&&dp[i-1][j-1];
        		} 

        	}
        }
        return dp[n1][n2];

    }
};
void test000(){
	string s="aa";
	string p="a*";
	bool res=Solution().isMatch(s,p);
	cout<<"你的输出结果是："<<res<<endl;
	bool standerd=true;
	cout<<"正确答案是："<<standerd<<endl;
	if(compared_bool(res,standerd))
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