class Solution {
   public:
    vector<vector<int>> mem;
    int dp(int i, int cur, vector<int>& coins) {
        if (i >= coins.size()) return 0;
        if (cur == 0) return 1;
        if (mem[i][cur] != -1) return mem[i][cur];
        int x = 0;
        for (int j = i; j < coins.size(); j++) {
            if (cur - coins[j] >= 0) x += dp(j, cur - coins[j], coins);
        }

        return mem[i][cur] = x;
    }
    int change(int amount, vector<int>& coins) {
        mem.assign(coins.size(), vector<int>(amount+1, -1));
        return dp(0, amount, coins);
    }
};
