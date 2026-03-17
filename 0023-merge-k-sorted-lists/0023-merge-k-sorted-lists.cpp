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
 auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    ListNode* merge(ListNode* ptr1, ListNode* ptr2){
        ListNode* dummy= new ListNode(0);
        ListNode*tail=dummy;
                
        while(ptr1!=nullptr &&ptr2!=nullptr){
            if(ptr1->val<=ptr2->val){
                tail->next=ptr1;
                ptr1=ptr1->next;
            }
            else{
                tail->next=ptr2;
                ptr2=ptr2->next;
            }
            tail=tail->next;
        }
        tail->next=(ptr1!= nullptr)? ptr1:ptr2;
        return dummy->next;
    }

    ListNode* helper(vector<ListNode*>& lists, int start, int end) {
// Base Case 1- No lists in this range
        if (start > end){
            return nullptr;
        }
// Base Case 2: Only one list left - it's already sorted!
        if (start == end){
            return lists[start];
        }
        int mid = start+ (end - start)/2;

        // Divide: Split the vector range, not the nodes
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid + 1, end);

        // Conquer: Merge the two results
        return merge(left, right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return helper(lists, 0, lists.size() - 1);        
    }
};