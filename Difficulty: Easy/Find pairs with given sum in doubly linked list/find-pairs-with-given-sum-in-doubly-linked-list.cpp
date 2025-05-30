// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node* temp=head;
        //Node* temp2=temp;
        vector<pair<int,int>>ans;
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        //Node* temp=head;
        while(head->data<tail->data){
            if(head->data+tail->data >target)tail=tail->prev;
            else if(head->data +tail->data <target)head=head->next;
            else{
                ans.push_back({head->data,tail->data});
                head=head->next;
                tail=tail->prev;
            }
        }
        return ans;
    }
};