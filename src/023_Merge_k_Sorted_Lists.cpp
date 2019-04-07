/*
	合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/
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
private:
    class cmp{
        public:
        bool operator()(ListNode *a,ListNode *b){
            return a->val>b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,cmp>queue;
        for(int i=0;i<n;i++){
            if(lists[i]!=nullptr){
                queue.push(lists[i]);
            }
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *cur=dummy;
        while(!queue.empty()){
            ListNode *node=queue.top();
            queue.pop();
            cur->next=node;
            cur=cur->next;
            
            if(node->next)
                queue.push(node->next);
        }
        return dummy->next;
    }
};
void test000(){
	vector<int>nums1={1,4,5},nums2={1,3,4},nums3={2,6};
	vector<ListNode *>lists;
	ListNode *l1=createList(nums1);
	lists.push_back(l1);
	ListNode *l2=createList(nums2);
	lists.push_back(l2);
	ListNode *l3=createList(nums3);
	lists.push_back(l3);
	printList(l1);
	printList(l2);
	printList(l3);
	ListNode *res=Solution().mergeKLists(lists);
	cout<<"merge:............"<<endl;
	printList(res);
}
int main(){
	cout<<"hello world"<<endl;
	test000();
	return 0;
}
