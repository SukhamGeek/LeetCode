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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0) return head;

        ListNode* mover= head;
        int p=1;
        while(mover->next){
            mover=mover->next;
            p++;
        }
        k=k%p;
        if(k==0) return head;
        int q= p-k-1;
        mover= head;
        while(q>0){
            mover=mover->next;
            q--;
        }
        ListNode* temp= mover;
        ListNode* nhead= mover->next;
        mover= mover->next;
        temp->next= nullptr;
        while(mover->next){
            mover= mover->next;
        }
        mover->next= head;
        head= nhead;
        return head;
    }
};