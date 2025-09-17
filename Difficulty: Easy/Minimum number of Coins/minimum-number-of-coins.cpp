class Solution {
  public:
    int findMin(int n) {
        // code here
       vector<int>v={10,5,2,1};
       int count=0;
       int i=0;
       while(n>0){
           if(n-v[i]>=0){
               n-=v[i];
               count++;
           }
           else i++;
       }
       return count;
    }
};