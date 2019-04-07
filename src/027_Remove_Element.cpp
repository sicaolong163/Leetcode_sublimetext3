#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())return 0;
        int index=0;
        for(auto num:nums){
            if(num!=val){
                nums[index++]=num;
            }
        }
        return index;
    }
};
void test027(){
	vector<int>nums={3,2,2,3};
	int val=3;
	int res=Solution().removeElement(nums,val);
	cout<<res<<endl;
}
int main(){
	test027();
	cout<<"hello world"<<endl;
	return 0;
}
