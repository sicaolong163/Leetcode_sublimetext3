#include<bits/stdc++.h>
using namespace std;

struct  ListNode{
    int val;
    ListNode *next;
    ListNode (int x):val(x),next(nullptr){}
};
ListNode *createList(vector<int>&nums){
    ListNode *dummy=new ListNode(-1);
    ListNode *cur=dummy;
    for(int i=0;i<nums.size();i++){
    	cur->next=new ListNode(nums[i]);
    	cur=cur->next;
    }
    return dummy->next;
}
void printList(ListNode *head){
	if(!head)return ;
    ListNode *p=head;
	while(p){
		cout<<p->val<<"->";
		p=p->next;
	}
	cout<<endl;
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *p1=l1;
        ListNode *p2=l2;
        ListNode *dummy=new ListNode(-1);
        ListNode *cur=dummy;
        if(p1->val<p2->val){
        	cur->next=p1;
        	cur=cur->next;
        	cur->next=mergeTwoLists(p1->next,p2);
        }else{
        	cur->next=p2;
        	cur=cur->next;
        	cur->next=mergeTwoLists(p1,p2->next);
        }
        return dummy->next;
    }
};

void test000(){
	cout<<"sicaolong"<<endl;
	vector<int>nums1={1,2,4};
	vector<int>nums2={1,3,4};
	ListNode *l1=createList(nums1);
	printList(l1);
	ListNode *l2=createList(nums2);
	printList(l2);
	cout<<"begin func:"<<endl;
	ListNode *res=Solution().mergeTwoLists(l1,l2);
	printList(res);
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}