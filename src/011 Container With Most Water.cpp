/*
	给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/
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
    int maxArea(vector<int>& nums) {
        int res=INT_MIN;
        if(nums.empty())return 0;
        int left=0,right=nums.size()-1;
        while(left<right){
        	res=max(res,min(nums[left],nums[right])*(right-left));
        	if(nums[left]<nums[right])
        		left++;
        	else
        		right--;
        }
        return res;
    }
};
void test000(){
	vector<int>nums={1,8,6,2,5,4,8,3,7};
	int res=Solution().maxArea(nums);
	cout<<"你的输出结果是："<<res<<endl;
	int standerd=49;
	cout<<"正确答案是："<<standerd<<endl;
	if(compared_num(res,standerd))
		cout<<"你的答案正确,再接再厉"<<endl;
	else 
		cout<<"你的答案错了，检查一下吧！"<<endl;

}

int main(){
	test000();
	cout<<"---------华丽的分割线----------"<<endl;
	cout<<"hello world"<<endl;
	return 0;
}