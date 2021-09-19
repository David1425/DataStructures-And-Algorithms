class suffix_array {
    int getVal(int i) {
        return ((val[i]<<(k+1)) | val[(i+x)%size]);
    }
    string s;
    int k, x;
    
    public:
    vector<int> ind, val;
    int size;
    
    void build(string str) {
        s = str+"$";
        vector<pair<char, int>> vec(size);
        for (int i = 0; i < size; i++) {
            vec[i] = {s[i], i};
        }
        sort(vec.begin(), vec.end());
        
        ind[0] = vec[0].second;
        val[ind[0]] = 0;
        for (int i = 1; i < size; i++) {
            ind[i] = vec[i].second;
            val[ind[i]] = val[ind[i-1]];
            if (vec[i].first != vec[i-1].first) val[ind[i]]++;
        }
        
        vector<pair<int, int>> a(size);
        
        k = 1;
        int l = log2(size);
        while (k <= l) {
            x = 1 << k;
            for (int i = 0; i < size; i++) a[i] = {getVal(i), i};
            sort(a.begin(), a.end());
            ind[0] = a[0].second;
            val[ind[0]] = 0;
            for (int i = 1; i < size; i++) {
                ind[i] = a[i].second;
                val[ind[i]] = val[ind[i-1]];
                if (getVal(ind[i]) != getVal(ind[i-1])) val[ind[i]]++;
            }
            k++;
        }
    }
    
    suffix_array(int n) : size(n+1), ind(n+1), val(n+1) {}
    suffix_array(string str) : s(str), size(int(str.size())+1), ind(int(str.size())+1), val(int(str.size())+1) { build(str); }
    
    string getSuffix(int i) { return s.substr(ind[i], size-ind[i]); }
};
