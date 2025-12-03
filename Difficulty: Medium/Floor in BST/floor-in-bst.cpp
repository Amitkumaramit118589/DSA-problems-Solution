/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int help(Node* root, int x, int ans) {
        if (root == NULL)
            return ans;

        if (root->data == x)
            return root->data;

        if (root->data < x)
            ans = root->data;

        if (x > root->data)
            return help(root->right, x, ans);
        else
            return help(root->left, x, ans);
    }

    int floor(Node* root, int x) {
        return help(root, x, -1);
    }
};
