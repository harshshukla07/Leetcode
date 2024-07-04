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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* ansHead = new ListNode();
        ListNode* ans = ansHead;
        int sum = 0;
        while(temp){
            if(temp->val!=0){
                sum += temp->val;
            }
            else if(sum!=0 && temp->val==0){
                ans->next = new ListNode(sum);
                sum = 0;
                ans = ans->next;
            }
            temp = temp->next;
        }
        return ansHead->next;
    }
};