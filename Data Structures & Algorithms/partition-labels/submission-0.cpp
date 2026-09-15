class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> freq;
        vector<int> ans;
        int mx = 0, cnt = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            freq[s[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            mx = max(mx, freq[s[i]]);
            if(i == mx){
                ans.push_back(++cnt);
                cnt = 0;
                continue;
            }
            cnt++;
        }
        return ans;
    }
};
