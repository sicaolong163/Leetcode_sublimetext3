#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n=s1.length(),m=s2.length();
        if(n>m)return false;
        vector<int>map1(128),map2(128);
        for(int i=0;i<n;i++){
            map1[s1[i]]++;
            map2[s2[i]]++;
        }
        if(map1==map2)return true;
        for(int i=n;i<m;i++){
            map2[s2[i-n]]--;
            map2[s2[i]]++;
            if(map2==map1)return true;
        }
        return false;
    }
};
void test000(){
	string s2="eidbaooo",s1="ab";
	bool flag=Solution().checkInclusion(s1,s2);
	cout<<flag<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}