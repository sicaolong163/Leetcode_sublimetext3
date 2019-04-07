
/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
找出 nums 中的三个整数，
使得它们的和与 target 最接近。
返回这三个数的和。
假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
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

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int n=nums.size();
        if(n<3)return 0;
        sort(nums.begin(),nums.end());
        int sum=0;
        int res=nums[0]+nums[1]+nums[n-1];
        for(int i=0;i<n;i++){
        	if(i>0&&nums[i]==nums[i-1])continue;
        	int left=i+1,right=n-1;
        	// int sum=nums[left]+nums[right];
        	while(left<right){
        		sum=nums[i]+nums[left]+nums[right];
        		if(sum<target)left++;
        		else right--;
        		if(abs(sum-target)<abs(res-target))
        			res=sum;
        	}
        }
        return res;
    }
};
void test000(){
	vector<int>nums={-1,2,1,-4};
	int target=1;
	int res=Solution().threeSumClosest(nums,target);
	cout<<"你的输出结果是："<<res<<endl;
	int  standerd=2;
	cout<<"正确答案是："<<standerd<<endl;
	if(compared_num(res,standerd))
		cout<<"your answer is right,nice  job~~~~~come on~~~~~~~ "<<endl;
	else 
		cout<<"your answer is wrong ，is a bad thing !!!!!please check it!!!!!!!!!!!!! "<<endl;

}

int main(){
	test000();
	cout<<"---------华丽的分割线----------"<<endl;
	cout<<"hello world"<<endl;
	return 0;
}