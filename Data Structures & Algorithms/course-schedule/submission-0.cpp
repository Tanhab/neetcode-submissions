class Solution {
   public:
    bool canFinish(int n, vector<vector<int>>& prerequisites)  
    {
        vector<int> in(n, 0);
        vector<vector<int>> adj(n);
        for(auto& v : prerequisites ){
            adj[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        queue<int>q;
        int seen = 0;
        for(int i = 0; i<n; i++){
            if(in[i] == 0) 
                q.push(i), seen++;
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int nei : adj[x]){
                if(--in[nei] ==0)
                    q.push(nei), seen++;
            }
        }

        return seen == n;


    }
};
