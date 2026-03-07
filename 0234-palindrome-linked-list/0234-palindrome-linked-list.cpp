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
//trying to do it in O(n) T.C. and O(1) S.C.
    ListNode* reverseList(ListNode*head,int k){
        ListNode*curr=head;
        ListNode*prev=nullptr;
        ListNode*next;
        while(curr->val!=k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int listLength(ListNode*head){     
        if(head==nullptr){
            return 0;
    }    
        return listLength(head->next)+1;
    }

    bool isPalindrome(ListNode* head) {
        int len= listLength(head);
        ListNode* ptr1=head;

        for(int i=0;i<len/2;i++){
            ptr1=ptr1->next;
        }
        int k=ptr1->val;

        ListNode* newList=reverseList(head,k);
        ListNode* ptr2=newList;
        
        for(int i=0;i<len/2;i++){
            if(ptr1->val!=ptr2->val){
                return false;
            }            
        } 
        return true;       
    }
};