#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string res;
        if(path.empty())return res;
        istringstream is(path);
        string tmp;
        vector<string>stack;
        while(getline(is,tmp,'/')){
            if(tmp=="."||tmp=="")continue;
            else if(tmp==".."){
                if(!stack.empty())stack.pop_back();
            }
            else{
                stack.push_back(tmp);
            }
        }
        for(auto str:stack){
            res+="/"+str;
        }
        return res.empty()?"/":res;
        
    }
};

void test000(){
	string path="/a/./b/../../c/";
	string res=Solution().simplifyPath(path);
	cout<<res<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}