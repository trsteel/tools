#include <iostream>
#include <algorithm>
using namespace std;

long long t, n, a[500001];

long long dfs2(int l, int r, int k);

long long dfs1(int l, int r, int k) {
    if(k==0) return 1;
    return max(a[l] * (a[l]<0?dfs2(l+1, r, k-1):dfs1(l+1, r, k-1)),
               a[r] * (a[r]<0?dfs2(l, r-1, k-1):dfs1(l, r-1, k-1)));
}

long long dfs2(int l, int r, int k) {
    if(k==0) return 1;
    return min(a[l] * (a[l]<0?dfs1(l+1, r, k-1):dfs2(l+1, r, k-1)),
               a[r] * (a[r]<0?dfs1(l, r-1, k-1):dfs2(l, r-1, k-1)));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a, a+n);
        cout<<dfs1(0, n-1, 5)<<endl;
    }
    return 0;
}
