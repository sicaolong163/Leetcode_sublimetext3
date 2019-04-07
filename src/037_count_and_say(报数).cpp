#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int i=1;i<n;i++){
            int cnt=1;
            char cur=res[0];
            string tmp="";
            for(int j=1;j<res.size();j++){
                if(res[j]!=cur){
                    tmp+=to_string(cnt);
                    tmp+=cur;
                    cur=res[j];
                    cnt=1;
                }else cnt++;
            }
            tmp+=to_string(cnt);
            tmp+=cur;
            res=tmp;
        }
        return res;
    }
};
void test000(){
	string res=Solution().countAndSay(3);
	cout<<res<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}