template<typename T>
class dsu_int { // Only for numbers values that are not too big
    public:
    vector<int> rank;
    vector<T> par;
    
    DSU(T n) {
        rank.assign(n, -1);
        par.assign(n, 0);
    }
    
    T find(T x) {
        if (par[x] == -1) return x;
        par[x] = find(par[x]);
        return par[x];
    }
    
    void merge(T a, T b) {
        T x = find(a), y = find(b);
        if (x == y) return;
        if (rank[x] > rank[y]) par[y] = x;
        else if (rank[x] < rank[y]) par[x] = y;
        else {
            par[y] = x;
            rank[x]++;
        }
    }
};