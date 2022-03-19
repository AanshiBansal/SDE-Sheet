//Time O(n)
//Space O(width)
//Using Level Order Traversal using queue

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int>curr=q.front();
            q.pop();
            mp[curr.second]=curr.first->data;
            if(curr.first->left!=NULL)
                q.push({curr.first->left,curr.second-1});
            if(curr.first->right!=NULL)
                q.push({curr.first->right,curr.second+1});
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            ans.push_back(itr->second);
        }
        return ans;
    }
};

//Time O(n)
//Space O(width+height)
// Predorder Traversal: Consider both height and distance
class Solution {
  public:
    void preOrder(Node* root, int distance, int height, map<int,pair<int,int>>&mp){
        if(root!=NULL){
            if(mp.find(distance)== mp.end() || height>=mp[distance].first){
                mp[distance]=make_pair(height,root->data);
            }
            preOrder(root->left, distance-1, height+1, mp);
            preOrder(root->right, distance+1, height+1, mp);
        }
    }
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        map<int,pair<int,int>>mp;
        preOrder(root,0,0,mp);
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            ans.push_back(itr->second.second);
        }
        return ans;
    }
};