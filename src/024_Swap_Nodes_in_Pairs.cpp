#include<bits/stdc++.h>
using namespace std;
struct  ListNode{
    int val;
    ListNode *next;
    ListNode (int x):val(x),next(nullptr){}
};
ListNode *createList(vector<int>&nums){
    ListNode *dummy=new ListNode(0);
    ListNode *cur=dummy;
    for(int i=0;i<nums.size();i++){
    	cur->next=new ListNode(nums[i]);
    	cur=cur->next;
    }
    return dummy->next;
}
void printList(ListNode *head){
	if(!head)return ;
	while(head){
		cout<<head->val<<"--> ";
		head=head->next;
	}
	cout<<endl;
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *cur=dummy;
        while(cur->next&&cur->next->next){
            ListNode *p1=cur->next;
            ListNode *p2=p1->next;
            p1->next=p2->next;
            p2->next=p1;
            cur->next=p2;
            cur=p1;
        }
        return dummy->next;
    }
};
void test000(){
	vector<int>nums={1,2,3,4};
	ListNode *head=createList(nums);
	head=Solution().swapPairs(head);
	printList(head);
}
int main(){
	test000();
	cout<<"hello world"<<endl;
	return 0;
}