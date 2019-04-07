#include<bits/stdc++.h>
using namespace std;


class Solution {
    /*
        1、就是利用两个map来 看出现的单词的个数；并且用substr来截取字符串；
        2、map1用来记录words中的单词出现的次数；
        3、每次在s串中取出 单词长度的字符串，然后再map1中来查看是否出现过；
        4、map2用来记录s字符串中出现的对应的单词出现的次数；
        5、如果在map2中出现的次数大于map1中出现的次数 则跳出循环继续找；
        6、两层循环一个是 s遍历；另一个是 出现的单词的个数 遍历；
        7、res中保存的是  s字符串遍历的索引；
    */
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res; 
        if(s.empty()||words.empty())return res;
        const int n=words.size();
        const int m=words[0].size();
        unordered_map<string,int>map1;
        for(string &str:words){//map1表示的是记录单词数组中 的单词的个数的map；
            map1[str]++;
        }
        for(int i=0;i<=(int)s.size()-m*n;i++)//注意i的取值范围；当然可以使 [0,s.szie());从前往后遍历来查找是否合适的字符串；
        {
            unordered_map<string,int>map2;//用来记录 字符串中存在得字符串的个数map2；
            int j=0;
            for(j=0;j<n;j++)//遍历的个数是单词的个数；也就是word的大小；
            {
                string str=s.substr(i+j*m,m);//截取m个长度的字符串 看看是否是一个word；
                if(map1.find(str)==map1.end())break;//在map1中查找看看是否存在；不存在就退出循环；
                map2[str]++;//map2中记录这个word串；
                if(map2[str]>map1[str])break;//如果在map2中出现的次数大于 在map1中出现的次数那么就退出循环；
            }
            if(j==n)res.push_back(i);//记录的是s串的下标的索引；
        }
        return res;
    }
};
void test000(){
	string  s = "barfoothefoobarman";
	vector<string>words = {"foo","bar"};
	vector<int> res=Solution().findSubstring(s,words);
	for(auto i:res)
		cout<<i<<" ";
	cout<<endl;
}

int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}