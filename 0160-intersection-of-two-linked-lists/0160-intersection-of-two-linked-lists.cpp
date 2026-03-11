/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }
        ListNode* ptr1=headA;
        ListNode* ptr2=headB;
        while(ptr1!=nullptr || ptr2!=nullptr){
            if(ptr1==ptr2){
                return ptr1;
            }
            if(ptr1==nullptr){
                ptr1=headB;
            }
            else if(ptr1!=nullptr){
                ptr1=ptr1->next;
            }
            if(ptr2==nullptr){
                ptr2=headA;
            }
            else if(ptr2!=nullptr){
                ptr2=ptr2->next;
            }
            
        }  
        return nullptr;                   
    }
};