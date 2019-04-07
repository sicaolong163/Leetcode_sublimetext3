#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())return 0;
        int cur=1,res=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])cur++;
            else{
                res=max(res,cur);
                cur=1;
            }
            res=max(res,cur);
        }
        return res;
    }
};
void test000(){
	vector<int>nums={1,3,5,4,7};
	int res=Solution().findLengthOfLCIS(nums);
	cout<<res<<endl;
}
int main(){
	test000();
	
	cout<<"hello world"<<endl;
	return 0;
}