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
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto& v : edges) {
           if(!dsu.unite(v[0],v[1]))
            return false;
        }
        int par = dsu.find(0);
        for (int i = 1; i<n;i++) {
           if(dsu.find(i)!= par)
            return false;
        }
        return true;
       
    }
};
