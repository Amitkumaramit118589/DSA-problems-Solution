
class Solution {
  public:
  
    Node* findPre(Node* root, int key)
    {
        Node* pre = NULL ;
        
        while(root)
        {
            if(root->data >= key) root = root->left ;
            
            else{
                pre = root ;
                root = root->right ;
            }
        }
        
        return pre ;
    }
    
    Node* findSuc(Node* root, int key)
    {
        Node* suc = NULL ;
        
        while(root) 
        {
            if(root->data <= key) root = root->right ;
            
            else {
                suc = root ;
                root = root->left ;
            }
        }
        
        return suc ;
    }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // S.C. = O(1)
        // T.C. = O(h)
        Node* pre = findPre(root, key) ;
        Node* suc = findSuc(root, key) ;
        
        return {pre, suc} ;
    }
};