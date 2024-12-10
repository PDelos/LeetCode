class Solution {
private:
    vector<pair<int, ListNode*>>sortedList;
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* temp = head;
        while(temp){
            sortedList.push_back({temp->val, temp});
            temp = temp -> next;
        }

        int n = sortedList.size();
        sort(sortedList.begin(), sortedList.end());
        for(int i = 0; i < n-1; i++){
            ListNode* currNode = sortedList[i].second;
            ListNode* nextNode = sortedList[i+1].second;
            currNode->next=nextNode;
        }
        ListNode* lstNode = sortedList[n-1].second;
        ListNode* newHead = sortedList[0].second;
        lstNode->next = nullptr;

        return newHead;
    }
};
