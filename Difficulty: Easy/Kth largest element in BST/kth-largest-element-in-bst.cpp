/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int count;
    
    void revInorder(Node* root, int k, int &ans) {
        if (root == NULL || count >= k) return;
        
        // pehle right (largest)
        revInorder(root->right, k, ans);
        
        count++;
        if (count == k) {
            ans = root->data;
            return;
        }
        
        // phir left
        revInorder(root->left, k, ans);
    }

    int kthLargest(Node *root, int k) {
        count = 0;      // har call me reset zaruri
        int ans = -1;   // safe default
        revInorder(root, k, ans);
        return ans;
    }
};
