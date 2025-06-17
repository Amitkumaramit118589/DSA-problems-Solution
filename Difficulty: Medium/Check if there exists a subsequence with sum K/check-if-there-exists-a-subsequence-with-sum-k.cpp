class Solution {
  public:
    bool fun(int index, vector<int> &arr, int n, int k) {
        if (k == 0) return true;             // Found a subsequence with sum k
        if (index == n) return false;        // Reached end without finding sum
        if (k < 0) return false;             // Sum became negative (optional optimization)

        // Choose to include or exclude the current element
        return fun(index + 1, arr, n, k - arr[index]) || fun(index + 1, arr, n, k);
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return fun(0, arr, n, k);  // ✅ return the result of recursive function
    }
};
