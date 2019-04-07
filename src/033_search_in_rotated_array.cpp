#include<bits/stdc++.h>
using namespace std;
class Solution {
	/*思路；就是先将这个数组分为有序的书序
	1、先看mid是在左侧还是在右侧；
	2、然后再看 target是在左侧还是在右侧；

	*/
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())return -1;
        int left=0,right=nums.size()-1;
        int mid=0;
        while(left<=right){
            mid=(right-left)/2+left;
            if(nums[mid]==target)return mid;
            //1、首先判断mid是在左边的递增区间还是在右侧的递增区间；
            else if(nums[mid]<nums[right]){//1、1在右侧的递增区间；
                if(target<=nums[right]&&target>nums[mid]){//在此基础上进行二分查找；
                    left=mid+1;
                }else right=mid-1;
            } 
            else{//1、2在左侧的递增区间；
                if(target>=nums[left]&&target<nums[mid]){
                    right=mid-1;
                }    else left=mid+1;
            }
        }
        return -1;
    }
    int search2(vector<int>& nums, int target) {
        if(nums.empty())return -1;
        int left=0,right=nums.size()-1,mid=0;
        while(left+1<right){
            mid=left+(right-left)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<nums[right]){
                if(target>nums[mid]&&target<=nums[right])left=mid;
                else right=mid;
            }else{
                if(target>=nums[left]&&target<nums[mid])right=mid;
                else left=mid;
            }
        }
        if(nums[left]==target)return left;
        if(nums[right]==target)return right;
        return -1;
    }
    
};

void test000(){
	vector<int>nums={4,5,6,7,0,1,2};
	int target=0;
	int res=Solution().search(nums,target);
	//0的索引应该是4；
	cout<<res<<endl;
}
void test002(){
	vector<int>nums={4,5,6,7,0,1,2};
	int target=3;
	int res=Solution().search2(nums,target);
	//不存在3应该返回-1；
	cout<<res<<endl;
}
int main(){
	test000();//
	test002();
	cout<<"hello world"<<endl;
	return 0;
}