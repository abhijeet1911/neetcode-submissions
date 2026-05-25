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
  int lengthlink(ListNode*head){
    int l=0;
    while(head!=NULL){
       head=head->next;
       l++;
    }
    return l;
  }


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=lengthlink(head);
            if(n==l){
                ListNode*temp=head->next;
                delete(head);
                return temp;
            }
            int travel=l-n;
            ListNode*prev=NULL;
            ListNode*curr=head;
            while(travel--){
                prev=curr;
                curr=curr->next;
                

            }
            prev->next=curr->next;
            delete(curr);
        
        return head;
    }
};
