class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> in(n, 0);
        vector<vector<int>> adj(n);
        for(auto& v : prerequisites ){
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        queue<int>q;
        int seen = 0;
        for(int i = 0; i<n; i++){
            if(in[i] == 0) 
                q.push(i), seen++, ans.push_back(i);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int nei : adj[x]){
                if(--in[nei] ==0)
                    q.push(nei), seen++, ans.push_back(nei);
            }
        }

        if(seen == n) return ans;
        else return {};
    }
};
