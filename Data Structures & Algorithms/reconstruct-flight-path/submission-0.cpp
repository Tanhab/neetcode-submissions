class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> out, in;
        for (auto& v : tickets) {
            adj[v[0]].push_back(v[1]);
            out[v[0]]++;
            if(!out.contains(v[1])) out[v[1]] = 0;
        }
        int n = tickets.size();
        for (auto& [_, v] : adj) {
            sort(v.rbegin(), v.rend());
        }
        int plus = 0, minus = 0;
        // check
        for (auto& [x, o] : out) {
            //cout << x << " " << o << endl;
            int diff = ssize(adj[x]) - o;
            //int diff = o - in;
            if (diff == 1)
                plus++;
            else if (diff == -1)
                minus++;
            else if (diff != 0)
                return {};
        }
        if (plus > 1 || minus > 1 || plus != minus) return {};
        //cout << " okay " << endl;
        vector<string> st, trail;
        st.push_back("JFK");
        while(!st.empty()){
            string s = st.back();
            //cout << s << endl;
            if(out[s]-- <= 0){
                trail.push_back(s);
                st.pop_back();

            }else{
                st.push_back(adj[s][out[s]]);
            }
        }
        reverse(trail.begin(), trail.end());
        //for(auto s : trail) cout << s << endl;

        if(trail.size() == n + 1){
            return trail;
        }else return {};
    }
};
