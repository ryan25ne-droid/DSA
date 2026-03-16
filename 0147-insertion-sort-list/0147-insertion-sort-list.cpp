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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* dummy= new ListNode(0);
        ListNode* ptr1=head;
        ListNode* ptr2=dummy;
        while(ptr1!=nullptr){
            ListNode* track=ptr1->next; //track the original list untouched
            ptr2=dummy //reset ptr2 to the start of sorted ll at every iteration
            while(ptr2->next!=nullptr && ptr2->next->val<ptr1->val){
                ptr2=ptr2->next;
            }
//we compared ptr2->next with ptr1 and not ptr2 directly as that can cause problems if the ptr1 val is less than 0. Because for first iteration of inner loop, ptr2-dummy and ptr2 val=0
            ptr1->next=ptr2->next;
            ptr2->next=ptr1;
            ptr1=track;
        }
        return dummy->next;                
    }
};
//ptr1 is used to traverse the original list. ptr2 is used to traverse the new sorted list.