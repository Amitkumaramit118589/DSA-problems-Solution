
class Solution {
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        vector<int> res;
        int n = arr.size();  // Define n as the size of arr
        for(int i = 0; i < indices.size(); i++) {
            int ind = indices[i];
            int cnt = 0;
            for(int j = ind + 1; j < n; j++) {
                if(arr[j] > arr[ind]) cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};
