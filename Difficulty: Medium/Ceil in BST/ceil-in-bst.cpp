class Solution {
  public:
    void check(Node* root,int &x,int input){
    if(!root) {
        return ;
    }
    
    if(root->data==input){
        x=input;
        return ;
    }
    
    else if(root->data<input){
        check(root->right,x,input);
    }
    
    else{
        x=root->data;
        check(root->left,x,input);
    }
   }

    int findCeil(Node* root, int input) {
        int x=-1;
        check(root,x,input);
        return x;
    }
};
