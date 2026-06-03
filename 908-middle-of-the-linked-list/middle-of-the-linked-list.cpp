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
    ListNode* middleNode(ListNode* head) {
        ListNode* slowhead = head;
        ListNode* fasthead = head;
        while(fasthead != NULL && fasthead->next != NULL){
            
            slowhead = slowhead->next;
            fasthead = fasthead->next->next;

        }
        return slowhead;
    }
};