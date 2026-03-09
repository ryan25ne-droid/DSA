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
        ListNode*ans=nullptr;
        ListNode*ptr1=list1;
        ListNode*ptr2=list2;
        if(list1==nullptr){
            return list2;
        }
        else if(list2==nullptr){
            return list1;
        }
        
        if(list1->val<=list2->val){
            ans=list1;
            ptr1=ptr1->next;
        }
        else{
            ans=list2;
            ptr2=ptr2->next;
        }
        ListNode*temp=ans;
        while(ptr1!=nullptr && ptr2!=nullptr){
            if (ptr1->val<=ptr2->val){
                temp->next=ptr1;
                ptr1=ptr1->next;
            }
            else{
                temp->next=ptr2;
                ptr2=ptr2->next;
            }
            temp=temp->next;
        }
        if(ptr1==nullptr){
                temp->next=ptr2;
        }
        else{
                temp->next=ptr1;
        }
    return ans;
    }
};
