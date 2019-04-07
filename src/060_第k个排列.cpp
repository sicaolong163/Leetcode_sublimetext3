#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        if(n==0)return res;
        vector<int>nums(n);
        for(int i=0;i<n;i++)
            nums[i]=i+1;
        vector<int>dp(n+1,1);
        for(int i=1;i<=n;i++)
            dp[i]=i*dp[i-1];
        k--;
        while(n>0){
            int index=k/dp[n-1];
            k=k%dp[n-1];
            res+=nums[index]+'0';
            nums.erase(nums.begin()+index);
            n--;
        }
        return res;
    }
};
void test000(){
	
	string res1=Solution().getPermutation(3,1);
	string res2=Solution().getPermutation(3,2);
	cout<<res1<<endl;
	cout<<res2<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}