class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
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
        return ans;
    }
};
