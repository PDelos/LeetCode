class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* current = prev->next;
        
        while (current) {
            if (current->next && current->val == current->next->val) {
                while (current->next && current->val == current->next->val) {
                    current = current->next;
                }
                prev->next = current->next;
            } else {
                prev = current;
            }
            current = current->next;
        }
        
        return dummy->next;
    }
};
