class Solution {
public:
    vector<int> twoOddNum(vector<int>& arr) {
        int n = arr.size();
        
        // Get the XOR of the two odd-occurring numbers
        int xorVal = 0;
        for (int i = 0; i < n; i++) {
            xorVal ^= arr[i];
        }

        // Get the rightmost set bit (differs the two numbers)
        int rightmostSetBit = xorVal & -xorVal;

        vector<int> ans(2, 0);

        for (int i = 0; i < n; i++) {
            if ((arr[i] & rightmostSetBit) == 0) {
                ans[0] ^= arr[i];  // First group
            } else {
                ans[1] ^= arr[i];  // Second group
            }
        }

        // Optional: Sort in descending order if required by platform
        if (ans[0] < ans[1]) swap(ans[0], ans[1]);
        
        return ans;
    }
};
