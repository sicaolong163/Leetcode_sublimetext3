#include<bits/stdc++.h>
using namespace std;


  // Definition for an interval.
 struct Interval {
      int start;
      int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
private:
    vector<Interval>res;
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())return res;
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval&b){return a.start<b.start;});
        // if(res.empty()||intervals)
        for(int i=0;i<intervals.size();i++){
            if(res.empty()||intervals[i].start>res.back().end)
                res.push_back(intervals[i]);
            else{
                res.back().end=max(res.back().end,intervals[i].end);
            }
        }
        return res;
    }
};
void test000(){
	
}
int main(){
	cout<<"hello world"<<endl;
	return 0;
}