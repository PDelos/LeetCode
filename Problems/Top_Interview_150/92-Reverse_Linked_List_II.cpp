class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(); // created dummy node
        dummy->next = head;
        ListNode *leftNode = dummy; // intialising leftNode pointer on dummy node
        
        for(int i = 0; i < left - 1; i++)
            leftNode = leftNode->next; // adjusting the leftNode pointer on it's actual index
        

        // prev is cnst, allways the node before the reversal
        ListNode* current = leftNode->next; 
        for(int i = left; i < right; ++i){
            ListNode* rightNode = current->next;
            current->next = rightNode->next;
            rightNode->next= leftNode->next;
            leftNode->next = rightNode;
        }
        return dummy->next;
    }
};
