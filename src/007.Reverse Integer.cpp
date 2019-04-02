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
    int reverse(int x) {
        long long res=0;
        while(x){
        	res=res*10+x%10;
        	x/=10;
        }
        if(res>INT_MAX||res<INT_MIN)
        	return 0;
        return (int )res;

    }
};
void test000(){
	int x=123;
	int res=Solution().reverse(x);
	cout<<"你的输出结果是："<<res<<endl;
	int  standerd=321;
	cout<<"正确答案是："<<standerd<<endl;
	if(compared_num(res,standerd))
		cout<<"你的答案正确,再接再厉"<<endl;
	else 
		cout<<"你的答案错了，检查一下吧！"<<endl;

}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}