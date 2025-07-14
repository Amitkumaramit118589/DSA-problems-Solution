class Solution {
  public:
    pair<int, int> get(int a, int b) {
        // code here
       a=a^b;
       b=a^b;
       a=a^b; //(a^b)^a
       return {a,b};
        
    }
};