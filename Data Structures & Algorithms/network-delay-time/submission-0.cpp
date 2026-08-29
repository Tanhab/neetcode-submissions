class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf  = INT_MAX / 4;
        vector<vector<pair<int,int>>> g(n+1);
        for (auto& e : times) {          // e = {u, v, w}
            g[e[0]].push_back({e[1], e[2]});
           // g[e[1]].push_back({e[0], e[2]});
        }
                vector<int> dist(n+1, inf);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            auto [d,x] = pq.top();
            pq.pop();
            for(auto [v,t]: g[x]){
                if(dist[x] + t < dist[v])
                    {
                        dist[v] = dist[x] + t;
                        pq.push({dist[v], v});
                    }
            }
        }
        int ans = 0;
        for(int i = 1; i<=n; i++ ){
            if(dist[i] == inf) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
