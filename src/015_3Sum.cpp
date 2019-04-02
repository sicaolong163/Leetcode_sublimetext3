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
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.empty())return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
        	if(i>0&&nums[i]==nums[i-1])continue;
        	int target=0-nums[i];
        	int left=i+1,right=nums.size()-1,sum=0;
        	while(left<right){
        		sum=nums[left]+nums[right];
        		if(sum==target){
        			res.push_back({nums[i],nums[left],nums[right]});
        			while(left<right&&nums[left+1]==nums[left])left++;
        			while(left<right&&nums[right-1]==nums[right])right--;
        			left++,right--;
        		}else if(sum<target){
        			left++;
        		}else{
        			right--;
        		}
        	}
        }
        return res;
    }
private:
 	vector<vector<int>>res;
};
void test000(){
	vector<int>nums={-1, 0, 1, 2, -1, -4};
	vector<vector<int>>res=Solution().threeSum(nums);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

}

int main(){
	test000();
	cout<<"---------华丽的分割线----------"<<endl;
	cout<<"hello world"<<endl;
	return 0;
}