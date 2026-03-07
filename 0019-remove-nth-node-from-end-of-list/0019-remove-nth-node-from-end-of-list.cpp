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
    int listLength(ListNode*head){     
        if(head==nullptr){
            return 0;
        }    
        return listLength(head->next)+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = listLength(head);
    int k = len - n + 1; // kth from start

    if (k > len || k <= 0) {
        cout << "Invalid position" << endl;
        return head;
    }

    // Case 1: remove head
    if (k == 1) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Case 2: remove other nodes
    ListNode* prev = head;
    for (int i = 1; i < k - 1; i++) {
        prev = prev->next;
    }

    ListNode* temp = prev->next;
    prev->next = temp->next; // works even if temp->next == nullptr
    delete temp;

    return head;
}
};