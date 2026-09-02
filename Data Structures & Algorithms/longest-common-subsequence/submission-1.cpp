class Solution {
   public:
    vector<vector<int>> mem;
    int dp(int i, int j, string& text1, string& text2) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (mem[i][j] != -1) return mem[i][j];

        if(text1[i] == text2[j])
            return mem[i][j] = 1 + dp(i + 1, j + 1, text1, text2);

        return mem[i][j] = max(dp(i + 1, j, text1, text2), dp(i, j + 1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        mem.assign(text1.size(), vector<int>(text2.size(), -1));

        return dp(0, 0, text1, text2);
    }
};
