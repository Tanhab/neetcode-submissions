class Solution {
public:
    struct DSU{
        int n;
        vector<int> p, r;
        DSU(int n) : p(n), r(n,0) { iota(p.begin(), p.end(), 0);}
        int find(int x){return x == p[x] ? x : p[x] = find(p[x]);}
        bool unite(int u, int v){
            u = find(u), v = find(v);
            if(u == v) return false;
            if(r[u] < r[v]) swap(u,v);
            p[v] = u;
            if(r[u] == r[v]) r[u]++;
            return true;
         }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>> edges;
        for(int i = 0; i< points.size() ; i++ )
            for(int j = i+1; j < points.size() ; j++ ){
                edges.push_back({(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])),i,j});
                //edges.push_back({(abs(x[0]-y[0])+abs(x[1]-y[1])),j,i});
            }
        sort(edges.begin(), edges.end());
        int total = 0, i = 0;
        DSU dsu(points.size());
        for(auto& [w,u,v] : edges){
            if(dsu.unite(u,v)){
                total+=w;
                i++;
            }
            if(i == points.size()) break;
        }
        return total;

        
    }
};
