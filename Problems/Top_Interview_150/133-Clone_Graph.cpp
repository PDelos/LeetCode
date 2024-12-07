class Solution {
private:
    unordered_map<Node*, Node*> clonedNodes; // Map to track cloned nodes

    Node* cloneDFS(Node* node) {
        // If the node is already cloned, return the clone
        if (clonedNodes.find(node) != clonedNodes.end()) {
            return clonedNodes[node];
        }

        // Create a new clone of the current node
        Node* clone = new Node(node->val);
        clonedNodes[node] = clone; // Store the clone in the map

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneDFS(neighbor));
        }

        return clone;
    }

public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL; // Handle empty graph
        return cloneDFS(node); // Start DFS clone
    }
};
