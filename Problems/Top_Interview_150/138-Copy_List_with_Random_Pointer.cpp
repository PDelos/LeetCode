class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> pointerHash;
        Node* temp = head;

        // First pass: create a copy of each node and store it in the hash map
        while(temp){
            pointerHash[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Second pass: set the next and random pointers for each node
        temp = head;
        Node* dummy = new Node(0); // dummy node to help with the list construction
        Node* curr = dummy;

        while(temp){
            curr->next = pointerHash[temp]; // Set the next pointer
            curr = curr->next;
            curr->random = pointerHash[temp->random]; // Set the random pointer
            temp = temp->next;
        }

        return dummy->next; // Return the deep-copied list (excluding the dummy node)
    }
};
