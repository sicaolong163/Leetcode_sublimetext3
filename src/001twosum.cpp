///*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

//示例:

//给定 nums = [2, 7, 11, 15], target = 9

//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>map;
       for(int i=0;i<nums.size();i++){
           if(map.count(target-nums[i])){
               return {map[target-nums[i]],i};
           }
           map[nums[i]]=i;
       }
   }
};

void test001(){
   vector<int>nums={2,5,7,11};
   vector<int>res=Solution().twoSum(nums,9);
   for_each(res.begin(),res.end(),[=](int a){cout<<a<<" ";});
}
int main()
{
   test001();
   return 0;
}

