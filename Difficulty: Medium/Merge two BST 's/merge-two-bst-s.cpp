/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        if (!root1 && !root2) return ans;

        // Two stacks for iterative inorder of both BSTs
        stack<Node*> s1, s2;
        Node *cur1 = root1, *cur2 = root2;

        while ((cur1 || !s1.empty()) || (cur2 || !s2.empty())) {
            // Leftmost chain of both trees
            while (cur1) {
                s1.push(cur1);
                cur1 = cur1->left;
            }
            while (cur2) {
                s2.push(cur2);
                cur2 = cur2->left;
            }

            // Decide which tree gives the next smallest element
            if (s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data)) {
                Node *node = s1.top();
                s1.pop();
                ans.push_back(node->data);
                cur1 = node->right;   // move to right subtree of this node
            } else {
                Node *node = s2.top();
                s2.pop();
                ans.push_back(node->data);
                cur2 = node->right;   // move to right subtree of this node
            }
        }

        return ans;
    }
};
