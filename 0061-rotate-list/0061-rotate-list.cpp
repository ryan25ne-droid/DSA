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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head== nullptr){
            return head;
        }

        int len= 1;
        ListNode* temp= head;
        while(temp->next!= nullptr){
            temp= temp->next;
            len++; 
        }

        ListNode* tail= temp;

        int shift= k % len;

        if(shift==0){
            return head;
        }

        tail-> next= head;

        for (int i=0; i<len-shift; i++) {
            temp = temp->next;
        }
        
        ListNode* ans= temp->next;
        temp->next= nullptr;
        return ans;
    }
};