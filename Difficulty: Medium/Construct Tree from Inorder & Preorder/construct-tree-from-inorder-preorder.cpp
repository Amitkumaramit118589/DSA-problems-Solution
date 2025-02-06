//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
     Node* constructTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &inorderMap, int &preIndex, int inStart, int inEnd) {
            // Base case
            if (inStart > inEnd) return nullptr;
        
            // Pick the current node from preorder traversal
            int rootValue = preorder[preIndex++];
            Node* root = new Node(rootValue);
        
            // Find the root index in inorder traversal
            int rootIndex = inorderMap[rootValue];
        
            // Recursively build left and right subtrees
            root->left = constructTree(preorder, inorder, inorderMap, preIndex, inStart, rootIndex - 1);
            root->right = constructTree(preorder, inorder, inorderMap, preIndex, rootIndex + 1, inEnd);
        
            return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
                unordered_map<int, int> inorderMap;
                int n = inorder.size();
                
                // Store indices of inorder elements for O(1) access
                for (int i = 0; i < n; i++) {
                    inorderMap[inorder[i]] = i;
                }
            
                int preIndex = 0;
                return constructTree(preorder, inorder, inorderMap, preIndex, 0, n - 1);
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends