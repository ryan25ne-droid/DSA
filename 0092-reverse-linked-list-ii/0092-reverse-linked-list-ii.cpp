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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right){
            return head;
        }

        ListNode dummy(0);  //by allocating in stack we don't have to manually delete dummy inorder to prevent memory leaks
        dummy.next = head;
        ListNode* prev = &dummy;

//Reach the node just before left position (start)
        for (int i =0; i <left-1; i++) {
            prev =prev->next;
        }

// Reverse the sublist from 'left' to 'right' in-place
        ListNode*curr = prev->next;
        for (int i=0; i<right-left; i++) {
            ListNode*temp= curr->next;
            curr->next =temp->next;
            temp->next =prev->next;
            prev->next =temp;
        }
        return dummy.next;
    }
};