class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        int vx = x.size(); // vertical cuts
        int hy = y.size(); // horizontal cuts

        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());

        long long cost = 0;   // internal safe calculation
        int i = 0, j = 0;
        int verticalPieces = 1, horizontalPieces = 1;

        while (i < vx && j < hy) {
            if (x[i] >= y[j]) { 
                cost += 1LL * x[i] * horizontalPieces;
                verticalPieces++;
                i++;
            } else {
                cost += 1LL * y[j] * verticalPieces;
                horizontalPieces++;
                j++;
            }
        }

        while (i < vx) {
            cost += 1LL * x[i] * horizontalPieces;
            i++;
        }

        while (j < hy) {
            cost += 1LL * y[j] * verticalPieces;
            j++;
        }

        return (int)cost; // final answer as int
    }
};
