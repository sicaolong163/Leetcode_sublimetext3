#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>>res;
    void dfs(vector<int>&nums,int index,vector<int>&cur,int target){
        if(target==0){
            res.push_back(cur);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            if(target<0)break;
            cur.push_back(nums[i]);
            dfs(nums,i,cur,target-nums[i]);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if(nums.empty())return res;
        sort(nums.begin(),nums.end());
        for(auto num:nums)cout<<num<<" ";
        	cout<<endl;
        vector<int>cur;
        dfs(nums,0,cur,target);
        return res;
    }
};

void test039(){
	vector<int>nums={2,3,6,7};
	int target=7;
	vector<vector<int>>res=Solution().combinationSum(nums,target);
	for(int i=0;i<res.size();i++){
		for(int j=0;i<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	cout<<"测试没有通过 什么原因"<<endl;
	test039();

	cout<<"hello world"<<endl;
	return 0;
}