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
        if(left==right){
            return head;
        }    

        ListNode* dummy= new ListNode(0);
        ListNode* LEFT= head;
        ListNode* RIGHT= head;
        ListNode* start= head;
        ListNode* end= head;

        int count=1;

        if(left==1){
            start=nullptr;
        }

        else{
            count=2;

            while(count<left){
                start= start->next;
                count++;
            }
            LEFT= start->next;
        }

        end= LEFT;
        while(count<right){
            end= end->next;
            count++;
        }
        RIGHT = end;
        end= end->next;

        ListNode* prev= LEFT;
        ListNode* curr= prev;
        ListNode* temp= curr;

        while(curr->next != end){
            temp= curr->next;
            curr->next= prev;
            prev= curr;
            curr= temp;
        }
        curr->next= prev;
        
        if(start!=nullptr){
            start->next= RIGHT;
        }
        LEFT->next= end;

        dummy->next= (left==1)? RIGHT: head;
        return dummy->next;
    }
};