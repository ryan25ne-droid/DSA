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
    vector<ListNode*> revSingle(ListNode* head, int k){
        ListNode* prev= nullptr;
        ListNode* curr= head;

        for(int i=0; i<k; i++){
            ListNode* temp= curr->next;
            curr->next= prev;
            prev= curr;
            curr= temp;
        }
        return {prev, head};

    }
    ListNode* reverseKGroup(ListNode* head, int k){
        ListNode dummy(0);
        dummy.next= head;
        ListNode* curr= &dummy;
        ListNode* travel= curr;

        while(travel!=nullptr){
            int count=0;
            bool flag= true;
            while(count<k){
                travel= travel->next;
                count++;
                if(travel==nullptr){
                    flag= false;
                    break;
                }
            }
            if(flag){
                ListNode* link= travel->next;
                vector<ListNode*> ptr= revSingle(curr->next, k);
                curr->next= ptr[0];
                ptr[1]->next= link;
                curr= ptr[1];
                travel= curr;
            }
        }
        return dummy.next;
    }
};