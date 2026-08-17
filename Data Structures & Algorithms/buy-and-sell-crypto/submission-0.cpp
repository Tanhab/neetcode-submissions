class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minP = -1;
        for (int x : prices) {
            if (minP == -1)
                minP = x;
            else {
                if (x> minP) {
                    ans = max(ans, x - minP);
                } else
                    minP = x;
            }
        }
        return ans;
    }
};
