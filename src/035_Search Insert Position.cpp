#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(right-left)/2+left;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};
void test000(){
	vector<int >nums={1,3,5,6};
	int target=5;
	int res=Solution().searchInsert(nums,target);
	cout<<"positon is: "<<res<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}