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
    int myAtoi(string str) {
        str.erase(0,str.find_first_not_of(' '));
        cout<<str<<endl;
        if(str.empty())return 0;
        int index=0,flag=1;
        long res=0;
        if(str[index]=='+')index++;
        else if(str[index]=='-'){
        	index++;
        	flag=-1;
        }
        while(isdigit(str[index])){
        	res=res*10+str[index]-'0';
        	index++;

        	if(flag==1&&res>INT_MAX)return INT_MAX;
        	if(flag==-1&&res>INT_MAX)return INT_MIN;
        }
        res*=flag;
        return (int )res;

    }
};
void test000(){

	string s="   -42";
	int res=Solution().myAtoi(s);
	cout<<"你的输出结果是："<<res<<endl;
	int standerd=-42;
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