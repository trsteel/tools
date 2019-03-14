class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<int>> cache(N+1, vector<int>((m+2)*(n+2), -1));
        return find(m, n, cache, N, i, j);
    }
    int find(int m, int n, vector<vector<int>>& cache, int N, int i, int j) {
        int key = (i+1)*(n+2)+j+1;
        if(cache[N][key]!=-1) return cache[N][key];
        if(i==-1 || i==m || j==-1 || j==n) {
            cache[N][key] = 1;
            return 1;
        } else if (N==0) {
            cache[N][key] = 0; 
            return 0;
        } else {
            int res = 0, mod=1e9+7;
            res += find(m, n, cache, N-1, i-1, j)%mod;
            res %= mod;
            res += find(m, n, cache, N-1, i+1, j)%mod;
            res %= mod;
            res += find(m, n, cache, N-1, i, j-1)%mod;
            res %= mod;
            res += find(m, n, cache, N-1, i, j+1)%mod;
            res %= mod;
            cache[N][key] = res;
            return res;
        }
        return 0;
    }
};