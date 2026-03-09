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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode* head; 
    if (list1->val <= list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }

    ListNode* prev = head;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            prev->next = list1;   // Stitch
            list1 = list1->next;  // Move list1 forward
        } else {
            prev->next = list2;   // Stitch
            list2 = list2->next;  // Move list2 forward
        }
        prev = prev->next;        // Move needle forward
    }

    if(list1==nullptr){
        prev->next=list2;
    }
    else{
        prev->next=list1;
    }

    return head;
    }
};