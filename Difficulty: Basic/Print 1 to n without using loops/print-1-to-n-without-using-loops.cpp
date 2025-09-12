class Solution {
  public:
    void printTillN(int n) {
        // code here
        if(n==0) return;
        int a=n;
        printTillN(a-1);
        cout<<a<<" ";
    }
};