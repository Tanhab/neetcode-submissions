class Solution {
   public:
    int countSubstrings(string s) {
        int total = 0;
        // odd
        int n = s.size();
        for (int i = 0; i < n; i++) {
            // odd
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                total++;
                l--;
                r++;
            }
            // even
            l = i , r = i+1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                total++;
                l--;
                r++;
            }
        }

        return total;


    }
};
