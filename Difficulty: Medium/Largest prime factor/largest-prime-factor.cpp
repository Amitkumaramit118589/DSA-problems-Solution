class Solution {
  public:
     int largestPrimeFactor(int n) 
    {
       vector<int>factors;
       for(int i=2;i*i<=n;i++)
       {
           if(n%i == 0)
           {
               factors.push_back(i);
               while(n%i==0)
               {
                   n=n/i;
               }
           }
       }
       if(n>1)
       {
           factors.push_back(n);
       }
       int m=factors.size();
       int maxi=INT_MIN;
       for(int i=0;i<m;i++)
       {
           maxi=max(maxi,factors[i]);
       }
       return maxi;
       
    }
};