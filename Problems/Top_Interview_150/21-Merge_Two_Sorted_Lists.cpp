class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(); // Dummy node to simplify list construction
        ListNode* curr = dummy;          // Pointer to construct the merged list

        // Merge the two lists
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;      // Attach list1's current node
                list1 = list1->next;     // Move list1 to the next node
            } else {
                curr->next = list2;      // Attach list2's current node
                list2 = list2->next;     // Move list2 to the next node
            }
            curr = curr->next;           // Move the merged list pointer forward
        }

        // Attach the remaining part of list1 or list2 (one of them will be nullptr)
        if (list1) curr->next = list1;
        if (list2) curr->next = list2;

        return dummy->next;              // Return the merged list, skipping the dummy node
    }
};
