/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    void leftTraversal(Node* root,vector<int> &v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) return;
        v.push_back(root->data);
        if(root->left){
            leftTraversal(root->left,v);   
        }else{
            leftTraversal(root->right,v);   
        }
    }
    void leafTraversal(Node* root,vector<int> &v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->data);
            return;
        }
        leafTraversal(root->left,v);
        leafTraversal(root->right,v);
    }
    void rightTraversal(Node* root,vector<int> &v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) return;
        if(root->right){
            rightTraversal(root->right,v);   
        }else{
            rightTraversal(root->left,v);   
        }
        v.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> v;
        if(root==NULL) return v;
        v.push_back(root->data);
        if(root->left==NULL && root->right==NULL) return v;
        if(root->left){
            leftTraversal(root->left,v);
        }
        leafTraversal(root,v);
        if(root->right){
            rightTraversal(root->right,v);
        }
        return v;
    }
};