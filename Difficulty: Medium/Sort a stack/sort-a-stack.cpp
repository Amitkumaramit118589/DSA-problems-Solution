/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insert(stack<int>&s,int x){
    if(s.empty() || s.top()<=x) {
        s.push(x);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,x);
    s.push(temp);
}
void help( stack<int>&s){
    if(s.size()==1 || s.empty()){
         return;
    }
    int top=s.top();
    s.pop();
    help(s);
    insert(s,top);
}
void SortedStack ::sort() {
    // Your code here
    
    help(s);
}