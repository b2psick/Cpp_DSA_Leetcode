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
        if(!node) 
            return node;
        Node* ansNode = new Node(node->val);
        unordered_set<Node*> set;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> mp;
        mp[node] = ansNode;
        set.insert(node);
        while(!q.empty()) {
            Node* a = q.front();
            q.pop();
            for(int i = 0; i < a->neighbors.size(); i++) {
                if(set.find(a->neighbors[i]) == set.end()){
                    Node* b = new Node(a->neighbors[i]->val);
                    mp[a->neighbors[i]] = b;
                    q.push(a->neighbors[i]);
                    set.insert(a->neighbors[i]);
                }
                mp[a]->neighbors.push_back(mp[a->neighbors[i]]);
            }
        }
        return ansNode;
    }
};