/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        // Your Code here
        Node* curr=head;
        Node* next=curr;
        Node* prev=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        Node* lasthead=prev;
        while(prev){
            if(prev->data !=9){
                prev->data+=1;
                break;
            }
            else{
                prev->data=0;
            }
            prev=prev->next;
        }
        if(prev==NULL)head->next=new Node(1);
         curr=lasthead;
         next=curr;
         prev=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        return prev;
       
        // return head of list after adding one
    }
};