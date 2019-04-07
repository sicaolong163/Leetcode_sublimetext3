#include<bits/stdc++.h>
using namespace std;
class Solution {
    /*
        双索引；leftMax表示左边的最高值；rightMax表示右侧的最高值；
        当height[left]<height[right]的时候 也就是左侧小的时候 维护左侧的参数；
        res+=leftMax-height[right];存在高度差 就必然会有水；
    */
public:
    int trap(vector<int>& height) {
        if(height.empty())return 0;
        int res=0,left=0,right=height.size()-1,leftMax=0,rightMax=0;
        while(left<right){
            if(height[left]<height[right]){
                leftMax=max(leftMax,height[left]);
                res+=leftMax-height[left];
                left++;
            }else{
                rightMax=max(rightMax,height[right]);
                res+=rightMax-height[right];
                right--;
            }
        }
        return res;
    }
};
void test000(){
	vector<int>nums={0,1,0,2,1,0,1,3,2,1,2,1};
	int res=Solution().trap(nums);
	cout<<res<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}