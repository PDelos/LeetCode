class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // create dummy and make it point to head
        ListNode* dummySmall = new ListNode();
        ListNode* dummyLarge = new ListNode();

        ListNode* smallTail = dummySmall;
        ListNode* largeTail = dummyLarge;
        ListNode* current = head;

        while(current){
            if(current->val < x){
                smallTail->next=current;
                smallTail=current;
            } else {
                largeTail->next=current;
                largeTail=current;
            }
            current=current->next;
        }

        smallTail->next=dummyLarge->next;
        largeTail->next=nullptr;
        delete smallDummy;
        delete largeDummy;

        return dummySmall->next;
    }
};
