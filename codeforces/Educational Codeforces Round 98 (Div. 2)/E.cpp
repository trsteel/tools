#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <iostream>
#include <stdio.h>
using namespace std;

int l[2001], r[2001];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<m;i++) {
        scanf("%d %d", &(l[i]), &(r[i]));
    }
    int res = 0;
    for(int i=0;i+k<=n;i++) for(int j=i;j+k<=n;j++) {
        int ans = 0;
        for(int x=0;x<m;x++) {
            ans += max(0, max(min(i+k, r[x])-max(i+1, l[x]), min(j+k, r[x])-max(j+1, l[x]))+1);
        }
        res = max(res, ans);
    }
    printf("%d\n", res);
    return 0;
}