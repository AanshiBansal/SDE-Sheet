// Time: O(V+E)
// Space: O(V)
// BFS
// https://leetcode.com/problems/clone-graph/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>mp;
        queue<Node*>q;
        if(node==NULL)
            return NULL;
        Node* root= new Node(node->val);
        mp[node]=root;
        q.push(node);
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            for(int i=0;i<front->neighbors.size();i++){
                if(mp.find(front->neighbors[i])==mp.end()){
                    mp[front->neighbors[i]]= new Node(front->neighbors[i]->val);
                    q.push(front->neighbors[i]);
                }
                mp[front]->neighbors.push_back(mp[front->neighbors[i]]);
            }
        }
        return root;
    }
};