/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* tail = node;
        while(curr->next!=NULL){
            curr->val = curr->next->val;
            if(curr->next->next==NULL){
                tail = curr;
            }
            curr = curr->next;
        }
        tail->next = NULL;
    }
};