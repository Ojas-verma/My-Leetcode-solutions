class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }
    bool compare(ListNode* p1, ListNode* p2){
        while(p2 != NULL){
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;
        ListNode* middle = findMiddle(head);
        ListNode* secondHalf = reverseLL(middle);
        return compare(head, secondHalf);
    }
};