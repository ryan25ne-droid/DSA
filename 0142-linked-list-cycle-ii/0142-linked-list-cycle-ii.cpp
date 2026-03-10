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
    ListNode *detectCycle(ListNode *head) {
    ListNode*slow=head;
    ListNode*fast=head;
    bool isCycle=false;
    while(fast!=nullptr &&fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if (slow==fast){
            isCycle=true;
            break;
        }
    }
    if(isCycle==false){
        return nullptr;;
    }
    else{
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return fast;
    }        
};