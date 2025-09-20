class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        vector<int>start;
        vector<int>end;
        for(int i=0;i<arr.size();i++){
           
                start.push_back(arr[i][0]);
                end.push_back(arr[i][1]);
            
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int room=0;
        int ans=0;
        int i=0;
        int j=0;
        while(i<start.size() && j<end.size()){
            if(start[i]<end[j]){
                i++;
                room++;
                ans=max(ans,room);
            }
            else if(start[i]>end[j]){
                room--;
                j++;
            }
            else{
                i++;
                j++;
            }
                
        }
        return ans==1;
    }
};