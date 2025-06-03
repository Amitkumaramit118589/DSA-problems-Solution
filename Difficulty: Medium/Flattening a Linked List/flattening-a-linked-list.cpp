/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
     Node* mergeLists(Node* first, Node* second) {
        Node* newList = NULL;
        if (first->data <= second->data) {
            newList = first;
            first = first->bottom;
        } else {
            newList = second;
            second = second->bottom;
        }
        
        Node* newPtr = newList;
        
        while (first != NULL && second != NULL) {
            if (first->data <= second->data) {
                newPtr->bottom = first;
                first = first->bottom;
            } else {
                newPtr->bottom = second;
                second = second->bottom;
            }
            newPtr = newPtr->bottom;
        }
        
        if (first != NULL) {
            newPtr->bottom = first;
        }
        
        if (second != NULL) {
            newPtr->bottom = second;
        }
        
        return newList;
    }
    
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node* newRoot = root;
        Node* nextPtr = root->next;
        // Merge two bottom lists at a time
        while (nextPtr != NULL) {
            newRoot = mergeLists(newRoot, nextPtr);
            nextPtr = nextPtr->next;
        }
        return newRoot;
    }
};