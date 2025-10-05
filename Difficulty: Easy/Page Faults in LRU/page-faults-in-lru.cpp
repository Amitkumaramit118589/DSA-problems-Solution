// User function Template for C++

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        // code here
        unordered_map<int,int>um;
        int c=0;
        list<int>l;
        for(int i=0;i<N;i++){
            
            if(l.size()==C){
                if(um.find(pages[i])==um.end()){
                    um[pages[i]]=1;
                    um.erase(l.front());
                    l.pop_front();
                    l.push_back(pages[i]);
                    c++;
                }
                else{
                    l.remove(pages[i]);
                    l.push_back(pages[i]);
                }
            }
            else{
                if(um.find(pages[i])==um.end()){
                    um[pages[i]]=1;
                    l.push_back(pages[i]);
                    c++;
                }
                else{
                    l.remove(pages[i]);
                    l.push_back(pages[i]);
                }
            }
        }
        return c;
    }
};