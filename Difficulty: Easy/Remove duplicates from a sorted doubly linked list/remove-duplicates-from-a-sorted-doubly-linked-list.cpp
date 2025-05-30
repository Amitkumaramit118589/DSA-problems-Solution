/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        struct Node* temp=head;
        while(temp && temp->next){
           if(temp->data==temp->next->data){
               struct Node* dupli=temp->next;
               temp->next=dupli->next;
               if(dupli->next)dupli->next->prev=temp;
           }
           else{
               temp=temp->next;
           }
        }
        return head;
    }
};