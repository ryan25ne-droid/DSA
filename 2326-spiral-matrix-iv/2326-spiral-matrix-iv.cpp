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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector(n,-1));
        int srow=0, scol=0;
        int erow=m-1, ecol=n-1;
        if(head==nullptr){
            return ans;
        }

        ListNode*ptr=head;

        while(srow<=erow && scol<=ecol){
            for(int i=scol;i<=ecol;i++){
                if(ptr==nullptr){
                    return ans;
                }
                ans[srow][i]=ptr->val;
                ptr=ptr->next;
            }
            srow++;
            for(int i=srow;i<=erow;i++){
                if(ptr==nullptr){
                    return ans;
                }
                ans[i][ecol]=ptr->val;
                ptr=ptr->next;
            }
            ecol--;
            if(srow<=erow){
                for(int i=ecol;i>=scol;i--){
                    if(ptr==nullptr){
                        return ans;
                    }
                    ans[erow][i]=ptr->val;
                    ptr=ptr->next;
                }
                erow--;
            }
            if(scol<=ecol){
                for(int i=erow;i>=srow;i--){
                    if(ptr==nullptr){
                        return ans;
                    }
                    ans[i][scol]=ptr->val;
                    ptr=ptr->next;
                }
                scol++;
            }
        } 
        return ans;       
    }
};