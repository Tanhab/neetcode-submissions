class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = ssize(temp);
        vector<int> ans(n, 0);
        st.push({temp[0], 0});
        for (int i = 1; i < n; i++) {
            while (!st.empty() && temp[i] > st.top().first) {
                auto& a = st.top();
                st.pop();
                ans[a.second] = i - a.second;
            }
            st.push({temp[i], i});
        }
        return ans;
    }
};
