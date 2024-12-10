class Solution {
private:
    ListNode* merge2List(ListNode* lst1, ListNode* lst2){
        ListNode* dummy = new ListNode();
        ListNode* iter = dummy;

        while(lst1 && lst2){
            if(lst1->val < lst2->val){
                iter->next=lst1;
                lst1=lst1->next;
            }
            else {
                iter->next=lst2;
                lst2=lst2->next;
            }
            iter=iter->next;
        }
        if(lst1) iter->next=lst1;
        if(lst2) iter->next=lst2;

        return dummy->next;
    }

    ListNode* divideAndConquer(vector<ListNode*>& lists, int left, int right){
        if(left == right) return lists[left];

        int mid = left+(right-left)/2;
        return merge2List(divideAndConquer(lists, left, mid), divideAndConquer(lists, mid+1, right));
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return divideAndConquer(lists, 0, lists.size() - 1);
    }
};
