// Question - Clone Graph
// Question link - https://leetcode.com/problems/clone-graph/

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
        if(node == NULL)
            return NULL;
        Node* head = new Node();
        head->val = node->val;
        queue<pair<Node*, Node*>> q;
        q.push({node, head});
        vector<Node* > vis(105, NULL);
        vis[node->val] = head;

        while(!q.empty())
        {
            Node *old_ad = q.front().first;
            Node *new_ad = q.front().second;
            q.pop();

            for(auto it: old_ad->neighbors)
            {
                if(vis[it->val] == NULL)
                {
                    Node *temp = new Node();
                    temp->val = it->val;
                    q.push({it, temp});
                    vis[it->val] = temp;
                    
                }
                new_ad->neighbors.push_back(vis[it->val]);
            }
        }

        return head;
    }
};