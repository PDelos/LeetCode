class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Handle edge cases
        if (!head || k == 0) return head;

        // Find the length of the list and the last node
        int n = 1;
        ListNode* lstNode = head;
        while (lstNode->next) {
            lstNode = lstNode->next;
            ++n;
        }

        // Adjust k to handle cases where k >= n
        k %= n;
        if (k == 0) return head; // No rotation needed

        // Find the new head (n - k steps from the beginning)
        ListNode* newTail = head;
        for (int i = 1; i < n - k; ++i) {
            newTail = newTail->next;
        }

        // Update the list pointers to perform the rotation
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        lstNode->next = head;

        return newHead;
    }
};
