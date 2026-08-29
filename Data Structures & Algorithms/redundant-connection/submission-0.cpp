class Solution {
    struct DSU {
        vector<int> p, r;
        DSU(int n) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
        int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
        bool unite(int a, int b){
            a = find(a), b = find(b);
            if(a==b) return false;
            if(r[a] < r[b]) swap(a,b);
            p[b] = a;
            if(r[a] == r[b]) r[a]++;
            return true;
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size() + 1);
        for (auto& v : edges) {
           if(!dsu.unite(v[0],v[1]))
            return {v[0],v[1]};
        }
        
        return {};
    }
};
