class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int inf = INT_MAX/4;
        vector<int> dist(n,inf), temp(n,inf);
        dist[src] = temp[src] = 0;
        for(int i = 0; i<= k ; i++){
            temp = dist;
            for(auto& edge : flights){
               int u = edge[0] , v = edge[1], w = edge[2];
               if(temp[u] + w < dist[v]){
                dist[v] = temp[u] + w;
               }
            }

        }

         return dist[dst] == inf ? -1 : dist[dst];
    }
};
