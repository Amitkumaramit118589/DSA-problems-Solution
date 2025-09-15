bool cmp(pair<int,int>v,pair<int,int>v2){
        double r1=(v.first*1.0)/(v.second*1.0);
        double r2=(v2.first*1.0)/(v2.second*1.0);
        return r1>r2;
    }
class Solution {
  public:
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<int,int>>frac;
        
        for(int i=0;i<n;i++){
            frac.push_back({val[i],wt[i]});
        }
        sort(frac.begin(),frac.end(),cmp);
        
        double ans=0;
        for(int i=0;i<n;i++){
            if(frac[i].second<=capacity){
                ans+=frac[i].first;
                capacity-=frac[i].second;
            }
            else{
                ans+=(frac[i].first*1.0)/(frac[i].second*1.0)*capacity;
                capacity=0;
                break;
            }
        }
        return ans;
    }
};
