/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        map<int,int>m;
        q.push({root,0});
        
        while(q.size()>0){
            Node* curr=q.front().first;
            int currhd=q.front().second;
            q.pop();
            
            if(m.find(currhd)==m.end()){
                m[currhd]=curr->data;
            }
            
            if(curr->left!=NULL){
                q.push({curr->left,currhd-1});
            }
            if(curr->right!=NULL){
                q.push({curr->right,currhd+1});
            }
        }
        vector<int>ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};