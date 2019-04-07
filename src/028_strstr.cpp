#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        if(n<m)return -1;
        for(int i=0;i<=n-m;i++){
            if(haystack.substr(i,m)==needle)
                return i;
        }
        return -1;
    }
};

void test0028(){
	string haystack="sicaolong";
	cout<<haystack<<endl;
	string needle="ca";
	cout<<needle<<endl;
	int res=Solution().strStr(haystack,needle);
	cout<<res<<endl;
}
int main(){

	 test0028();
	// cout<<"123"<<endl;
	// cout<<"hello world"<<endl;
	return 0;
}