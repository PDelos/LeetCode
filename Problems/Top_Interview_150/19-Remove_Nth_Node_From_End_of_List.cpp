class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next=head;

        int k = 0;
        ListNode* count = dummy;
        ListNode* temp = dummy;
        while(count){
            if(n < k) temp=temp->next;
            count=count->next;
            ++k;
        }
        
        if(temp && temp->next){
            temp->next = temp->next->next;
        }

        return dummy->next;
    }
};
