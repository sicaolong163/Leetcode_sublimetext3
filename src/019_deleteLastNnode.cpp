#include<bits/stdc++.h>
using namespace std;
/*给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。*/
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
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return nullptr;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *pre=dummy;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast&&n-->0){
        	fast=fast->next;
        }
        if(n>0)return nullptr;
        while(fast){
        	fast=fast->next;
        	slow=slow->next;
        	pre=pre->next;
        }
        pre->next=slow->next;
        delete slow;
        return dummy->next;
    }
};
void test000(){
	vector<int>nums={1,2,3,4,5};
	ListNode *head=createList(nums);
	printList(head);
	head=Solution().removeNthFromEnd(head,2);
	printList(head);

}

int main(){
	test000();
	cout<<"---------华丽的分割线----------"<<endl;
	cout<<"hello world"<<endl;
	return 0;
}