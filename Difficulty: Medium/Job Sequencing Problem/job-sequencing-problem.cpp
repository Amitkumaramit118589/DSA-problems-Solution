class Solution {
  public:
    vector<int> jobSequencing(vector<int> &v1, vector<int> &v2) {
        // code here
        vector<pair<int,int>>v;
        int n=v2.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({v1[i],v2[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int ans=0,q=0;
        for(auto i:v)
        {
            int a=i.first,b=i.second;
           
            if(q<a)
            {
                q++;
                pq.push(b*-1);
              
            }
            else if(q!=0&&(pq.top()*-1)<b)
            {
               
                pq.pop();
                pq.push(b*-1);
            }
        }
        while(!pq.empty())
        {
            ans-=pq.top();
            pq.pop();
        }
        return {q,ans};
        
    }
};