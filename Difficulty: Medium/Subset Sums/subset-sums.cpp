class Solution {
  public:
    vector<int>ans;
    //ans.push_back(0);
    void help(vector<int>curr,int i,int sum){
        if(i==curr.size()){
            ans.push_back(sum);
            return;
        }
        help(curr,i+1,sum);
        help(curr,i+1,sum+curr[i]);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        help(arr,0,0);
        return ans;
    }
};