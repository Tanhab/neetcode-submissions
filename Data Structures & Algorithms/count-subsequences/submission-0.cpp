class Solution {
   public:
    vector<vector<int>> mem;
    int n, m;
    int dp(int i, int j, string& s, string& t) {
        // if (j == m) return 1;
        if (i >= n || j >= m) return 0;
        if (mem[i][j] != -1) return mem[i][j];
        int ret = 0;
        if (s[i] == t[j] && j + 1 == m)
            ret = 1;
        else if (s[i] == t[j])
            ret += dp(i + 1, j + 1, s, t);
        // if (s[i] == t[0] && i > 0) ret += dp(i + 1, 1, s, t);

        ret += dp(i + 1, j, s, t);
        return mem[i][j] = ret;
    }
    int numDistinct(string s, string t) {
        n = s.size(), m = t.size();
        if (m > n) return 0;
        mem.assign(n, vector<int>(m, -1));
        return dp(0, 0, s, t);
    }
};
