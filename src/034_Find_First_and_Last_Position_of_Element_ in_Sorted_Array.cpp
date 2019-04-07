#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int findfirstEqual(vector<int>&nums,int target){
        int left=0,right=nums.size()-1,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]>=target)right=mid-1;
            else left=mid+1;
        }
        if(left<=nums.size()-1&&nums[left]==target)return left;
        return -1;
    }
    int findLastEqual(vector<int>&nums,int target){
        int left=0,right=nums.size()-1,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]<=target)left=mid+1;
            else right=mid-1;
        }
        if(right>=0&&nums[right]==target)return right;
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        int x1=findfirstEqual(nums,target);
        int x2=findLastEqual(nums,target);
        return {x1,x2};
    }
};
void test000(){
	vector<int>nums={5,7,7,8,8,10};
	int target1=8,target2=9;
	vector<int>res1=Solution().searchRange(nums,target1);
	cout<<res1[0]<<" "<<res1[1]<<endl;
	vector<int>res2=Solution().searchRange(nums,target2);
	cout<<res2[0]<<" "<<res2[1]<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}