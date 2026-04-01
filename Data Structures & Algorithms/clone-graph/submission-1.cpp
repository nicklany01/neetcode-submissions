/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        unordered_map<Node*, Node*> m;
        // use dfs to make an identical graph, visiting each node
        unordered_set<Node*> visited;
        function<void(Node*,Node*)> dfs = [&](Node* curr, Node* clone) {
            if (visited.contains(curr)) return;
            visited.insert(curr);
            for (auto neighbor : curr->neighbors) {
                Node* clonedneighbor;
                if (!m.contains(neighbor)) {
                    clonedneighbor = new Node(neighbor->val);
                    m[neighbor] = clonedneighbor;
                } else {
                    clonedneighbor = m[neighbor];
                }
                clone->neighbors.push_back(clonedneighbor);
                dfs(neighbor, clonedneighbor);
            }
        };
        Node* head = new Node(node->val);
        m[node] = head;
        dfs(node, head);
        return head;     
    }
};
