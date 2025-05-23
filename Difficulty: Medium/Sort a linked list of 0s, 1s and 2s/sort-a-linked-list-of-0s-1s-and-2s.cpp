/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0)cnt0++;
            else if(temp->data == 1)cnt1++;
            else cnt2++;
            temp=temp->next;
        }
        Node* dummy=new Node(-1);
        Node* t=dummy;
        for(int i=0;i<cnt0;i++){
            Node* c=new Node(0);
            t->next=c;
            t=t->next;
        }
        for(int i=0;i<cnt1;i++){
            Node* c=new Node(1);
            t->next=c;
            t=t->next;
        }
        for(int i=0;i<cnt2;i++){
             Node* c=new Node(2);
            t->next=c;
            t=t->next;
        }
        return dummy->next;
    }
};