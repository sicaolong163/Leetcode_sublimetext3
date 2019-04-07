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
/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class Solution {
private:
	vector<vector<int>> res;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	int n=nums.size();
        if(nums.empty())return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
        	if(i>0&&nums[i]==nums[i-1])continue;
        	for(int j=i+1;j<n;j++){
        		if(j>1&&nums[j]==nums[j-1])continue;
        		int left=j+1,right=n-1;
        		while(left<right){
        			int sum=nums[i]+nums[j]+nums[left]+nums[right];
        			if(sum==target){
        				res.push_back({nums[i],nums[j],nums[left],nums[right]});
        				while(left<right&&nums[left+1]==nums[left])left++;
        				while(left<right&&nums[right-1]==nums[right])right--;
        				left++,right--;
        			}
        			else if(sum<target){
        				left++;
        			}else{
        				right--;
        			}
        		}
        	}
        }
        return res;
    }
};
void test000(){
	vector<int>nums={1, 0, -1, 0, -2, 2};
	int target=0;
	vector<vector<int>>res=Solution().fourSum(nums,0);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	// cout<<"你的输出结果是："<<res<<endl;
	// string standerd="PINALSIGYAHRPI";
	// cout<<"正确答案是："<<standerd<<endl;
	// if(compared(res,standerd))
	// 	cout<<"your answer is right,nice  job~~~~~come on~~~~~~~ "<<endl;
	// else 
	// 	cout<<"your answer is wrong ，is a bad thing !!!!!please check it!!!!!!!!!!!!! "<<endl;

}

int main(){
	test000();
	cout<<"---------华丽的分割线----------"<<endl;
	cout<<"hello world"<<endl;
	return 0;
}