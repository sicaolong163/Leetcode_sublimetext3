#include<bits/stdc++.h>
using namespace std;
class Solution{
    
//1、从后边找到第一个 比后面的数小的数fs索引；
//2、再从后面找到比fs位置大的数  注意是第一个索引 fb；然后交换之后就可以了
//3、再从fb+1，到数组的最后一位进行反转；
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())return ;
        int fs=-1;//找到第一个比后面位置小的数；
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                fs=i;
                break;
            }
        }
        if(fs==-1){//注意这里没有找到的时候，他是一个逆序的 只需要一次逆序就可以得到了，所以后面要跟一个return直接返回结果；
            sort(nums.begin(),nums.end());
            return ;
        }
        int fb=-1;
        for(int i=nums.size()-1;i>fs;i--){
            if(nums[i]>nums[fs]){
                fb=i;
                break;
            }
        }
        swap(nums[fs],nums[fb]);
        int left=fs+1,right=nums.size()-1;
        // reverse(nums,left,right);
        while(left<right){
            swap(nums[left++],nums[right--]);
        }
    }
};
void test000(){
	vector<int>nums={1,2,6,4,5};
	cout<<"原来的排列是：";
	for(auto num:nums){
		cout<<num<<" ";
	}
	cout<<endl;
	Solution().nextPermutation(nums);
	cout<<"下一个排列是：";
	for(auto num:nums){
		cout<<num<<" ";
	}
	cout<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}