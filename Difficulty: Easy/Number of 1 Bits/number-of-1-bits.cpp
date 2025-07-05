class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        while(n){
            if(n&1 ==1)count++;
            n=n>>1;
        }
        return count;
    }
};