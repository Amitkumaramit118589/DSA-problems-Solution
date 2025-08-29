class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        int i=0,j=0;
        map<char,int>mp;
        int result=-1;
        while(j<n){
            mp[s[j]]++;
            while(i<j && mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k) result= max(result,j-i+1);
            j++;
        }
        return result;
    }
};