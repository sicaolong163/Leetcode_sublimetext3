#include<bits/stdc++.h>
using namespace std;
/*给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
        int res=0;
        for(auto num:nums){
            if(set.count(num-1))continue;
            
            int len=0;
            while(set.count(num+len))len++;
            res=max(res,len);
        }
        return res;
    }
};
void test000(){
	vector<int>nums={100, 4, 200, 1, 3, 2};
	int res=Solution().longestConsecutive(nums);
	cout<<res<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}