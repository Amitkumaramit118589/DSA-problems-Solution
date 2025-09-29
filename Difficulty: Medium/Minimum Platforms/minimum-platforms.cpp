class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int count=0,maxi=0;
        int i=0,j=0;
        while(i<arr.size() && j<dep.size()){
            if(arr[i]<=dep[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};
