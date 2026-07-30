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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* ptr1= l1;
        ListNode* ptr2= l2;
        ListNode* dummy= new ListNode();
        ListNode* temp= dummy;

        int prevcarry=0;

        while(ptr1!= nullptr && ptr2!= nullptr){
            int result= ptr1->val+ ptr2->val+ prevcarry;
            if(result>=10){
                prevcarry=1;
                temp->next= new ListNode(result%10);
            }
            else{
                prevcarry=0;
                temp->next= new ListNode(result);
            } 
            ptr1= ptr1->next;
            ptr2= ptr2->next; 
            temp= temp->next;          
        }

        while(ptr1!=nullptr){
            if(prevcarry==0){
                temp->next= ptr1;
                break;
            }
            int result= ptr1->val+ prevcarry;
            if(result>=10){
                prevcarry=1;
                temp->next= new ListNode(result%10);
            }
            else{
                prevcarry=0;
                temp->next= new ListNode(result);
            }
            ptr1= ptr1->next;
            temp= temp->next;
        }
        while(ptr2!=nullptr){
            if(prevcarry==0){
                temp->next= ptr2;
                break;
            }
            int result= ptr2->val+ prevcarry;
            if(result>=10){
                prevcarry=1;
                temp->next= new ListNode(result%10);
            }
            else{
                prevcarry=0;
                temp->next= new ListNode(result);
            }
            ptr2= ptr2->next;
            temp= temp->next;
        }

        if(prevcarry==1){
            temp->next= new ListNode(1);
        }

        return dummy->next;        
    }
};