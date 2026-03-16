/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0){
            return nullptr;
        }
        if(n==1){
            return lists[0];
        }
        ListNode* ptr1=lists[0];
        ListNode* dummy=new ListNode(0); //to keep track of the head of the merged list, which is dummy->next
        
        for(int i=1;i<n;i++){
            ListNode* ptr2=lists[i];
            ListNode*curr=dummy; //for traversing the list
            while(ptr1!=nullptr &&ptr2!=nullptr){
                if(ptr1->val<=ptr2->val){
                    curr->next=ptr1;
                    ptr1=ptr1->next;
                }
                else{
                    curr->next=ptr2;
                    ptr2=ptr2->next;
                }
                curr=curr->next;
            }
            if(ptr1!=nullptr){
                curr->next=ptr1;
            }
            else{
                curr->next=ptr2;
            }
            ptr1=dummy->next;
        }
        return dummy->next;
    }
};