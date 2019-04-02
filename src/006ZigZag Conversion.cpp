#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // string convert(string s, int numRows) {
    //     int n=s.size();
    //     if(n==0)return "";
    //     string res;
    //     if(numRows<=1)return s;
    //     vector<string>str(numRows);
    //     int cur=0,step=0;
    //     for(int i=0;i<n;i++){
    //     	str[cur]+=s[i];
    //     	if(cur==numRows-1)step=-1;
    //     	if(cur==0)step=1;
    //     	cur+=step;
    //     }
    //     for(auto c:str){
    //     	res+=c;
    //     }
    //     return res;
    // }
    string convert(string s, int numRows) {
        string res="";
        int n=s.size();
        if(n==0)return res;
        if(numRows<=1)return s;
        vector<string>str(numRows);
        int cur=0,step=0;
        for(int i=0;i<n;i++){
            str[cur]+=s[i];
            if(cur==numRows-1)step=-1;
            if(cur==0)step=1;
            cur+=step;
        }
        for(auto c:str)
            res+=c;
        return res;
    }
};
bool compared(string s1,string s2){
	return s1==s2;
}
void test006(){
	string s = "PAYPALISHIRING";
	 int numRows = 4;
	string res=Solution().convert(s,numRows);
	cout<<res<<endl;
	string standerd="PINALSIGYAHRPI";
	cout<<standerd<<endl;
	if(compared(res,standerd))
		cout<<"你的答案正确,再接再厉"<<endl;
	else 
		cout<<"你的答案错了，检查一下吧！"<<endl;
}
int main(){
	test006();
	cout<<"hello world"<<endl;
	return 0;
}