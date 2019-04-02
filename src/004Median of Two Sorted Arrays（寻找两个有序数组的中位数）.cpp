/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1=nums1.size(),n2=nums2.size();
        if(n1>n2)return findMedianSortedArrays(nums2,nums1);
        const int k=(n1+n2+1)/2;//这个表示num1，nums2的左边一共应该有多少个数；
        int left=0,right =n1;//二分查找nums1的左边；
        int m1,m2;//代表nums1与nums2左边该取多少个数；
        while(left<right){
        	m1=(right-left)/2+left;
        	m2=k-m1;
        	if(nums1[m1]<nums2[m2-1]){
        		left=m1+1;
        	}else right=m1;
        }
        m1=left,m2=k-left;

        int mid1=max(m1<=0?INT_MIN:nums1[m1-1],m2<=0?INT_MIN:nums2[m2-1]);
        int mid2=min(m1>=n1?INT_MAX:nums1[m1],m2>=n2?INT_MAX:nums2[m2]);
        if((n1+n2)&1==1)return mid1;
        return (double)(mid1+mid2)/2;

    }
};
void test004(){
	vector<int>nums1={1,2},nums2={3,4};
	double res=Solution().findMedianSortedArrays(nums1,nums2);
	cout<<res<<endl;
}
int main(){
	test004();
	cout<<"hello world"<<endl;
	return 0;
}