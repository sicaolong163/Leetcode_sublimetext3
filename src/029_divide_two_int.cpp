#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    long divide(long ldid,long ldis){
        if(ldid==0||ldid<ldis)return 0;
        long sum=ldis;
        long cnt=1;
        while((sum+sum)<ldid){
            sum+=sum;
            cnt+=cnt;
        }
        return cnt+divide(ldid-sum,ldis);
    }
    // long divide(long ldividend,long ldivisor){
    //     if(ldividend==0||ldividend<ldivisor)return 0;
    //     long sum=ldivisor;
    //     long mult=1;
    //     while((sum+sum)<ldividend){
    //         sum+=sum;
    //         mult+=mult;
    //     }
    //     return mult+divide(ldividend-sum,ldivisor);
    // }
public:
    int divide(int dividend, int divisor) {
        int flag=1;
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0))flag=-1;
        long ldid=abs((long)dividend);
        long ldis=abs((long)(divisor));
        if(ldid==0||ldid<ldis)return 0;
        long lres=divide(ldid,ldis);
        lres*=flag;
        if(lres<INT_MIN)return INT_MIN;
        if(lres>INT_MAX)return INT_MAX;
        
        return (int)lres;
    }
};
void test029(){
	int a=10,b=3;
	int res=Solution().divide(a,b);
	cout<<res<<endl;
}
int main(){
	test029();
	cout<<"hello world"<<endl;
	return 0;
}