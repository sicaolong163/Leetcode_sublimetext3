#include<bits/stdc++.h>
using namespace std;

void test000(){
	string s="    si , cao  long  ";
	cout<<s<<endl;
	istringstream is(s);
	string res,tmp;
	while(getline(is,tmp,' ')){
		is>>tmp;
		cout<<tmp<<endl;
		res+=tmp;

	}
	cout<<res<<endl;
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}