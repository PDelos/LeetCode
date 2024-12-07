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
private:
    void reverseNextK(ListNode* &leftNode, const int &k) {
        
        ListNode* current = leftNode->next;
        for(int i = 1; i < k; ++i){
            ListNode* rightNode=current->next;
            current->next=rightNode->next;
            rightNode->next=leftNode->next;
            leftNode->next=rightNode;
        }

        leftNode = current;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // get list length
        ListNode* dummy = new ListNode();
        dummy->next = head;

        int n = 0;
        ListNode* count = dummy;
        while(count){
            count=count->next;
            ++n;
        } 

        ListNode* leftNode = dummy;
        int right = k;
        while(right<n){
            // reverse what is in between left and right
            reverseNextK(leftNode, k);
            right+=k;
        }
        return dummy->next;
    }
};
