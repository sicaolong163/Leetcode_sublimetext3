#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.empty())return res;
        dfs(s,0,"",0);
        return res;
    }
private:
    vector<string>res;
    void dfs(const string &s,const int &index,const string& ip,const int &cnt){
        if(cnt>4)return ;
        if(index==s.size()&&cnt==4){
            res.push_back(ip);
            return ;
        }
        for(int i=1;i<4;i++){
            if(index+i>s.size())break;
            string tmp=s.substr(index,i);//要截取的字符串；并且判断是不是合适的ip的一个子网段；
            //判断是不是第一位为0？或者说这三位之和大于255 都不合适；
            if((tmp.size()>1&&(to_string(stoi(tmp))!=tmp)) || (i==3&&tmp>="256"))continue;
            dfs(s,index+i,ip+tmp+(cnt==3?"":"."),cnt+1);//如果前面已经有三段了，那么最后就加空，否则就加“.”；
        }
    }
};
void test000(){
	string s= "25525511135";
	vector<string>res=Solution().restoreIpAddresses(s);
	for(auto ip:res){
		cout<<ip<<endl;
	}
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}