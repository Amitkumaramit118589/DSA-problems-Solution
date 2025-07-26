// User function Template for C++

class Solution {
  public:
    int n_tak_xor(int n){
        int mod=n%4;
        if(mod==0) return n;
        else if(mod==1) return 1;
        else if(mod==2) return n+1;
        else if(mod==3) return 0;
    }
    int findXOR(int l, int r) {
        // complete the function here
        int a= n_tak_xor(l-1);
        int c= n_tak_xor(r);
        int b= a^c;
        return b;
    }
};