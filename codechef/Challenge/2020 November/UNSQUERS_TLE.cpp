#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string.h>
using namespace std;

const long maxn = 100001;
long h[maxn], nexts[maxn], depth[maxn];
long cache1[1000][maxn], cache2[1000][maxn];

void prepare(long n) {
    priority_queue<pair<long, long>> pq;
    for(long i=0;i<n;i++) {
        nexts[i] = i;
        while(!pq.empty() && pq.top().first > -h[i]) {
            nexts[pq.top().second] = i; pq.pop();
        }
        pq.push({-h[i], i});
    }
    for(long i=n;i>=0;i--) {
        if(nexts[i]==i) depth[i] = 1;
        depth[i] = depth[nexts[i]] + 1;
    }
}

long find(long l, long r) {
    if(l==r) return 1;
    if(nexts[l]==l || nexts[l]>r) return 1;
    if(l&127) return 1 + find(nexts[l], r);
    if(cache1[l/128][r]>0) return cache1[l/128][r];
    return cache1[l/128][r] = 1 + find(nexts[l], r);
}

long cal(vector<long>& bottom, long idx, long r) {
    if(idx >= bottom.size() || bottom[idx] > r) return 0;
    if(idx&127) return max(find(bottom[idx], r), cal(bottom, idx+1, r));
    if(cache2[idx/128][r]>0) return cache2[idx/128][r];
    return cache2[idx/128][r] = max(find(bottom[idx], r), cal(bottom, idx+1, r));
}

int main() {
    memset(cache1, 0, sizeof(cache1));
    memset(cache2, 0, sizeof(cache2));
    long n, q, s, x, y, l, r, last=0;
    scanf("%ld %ld %ld", &n, &q, &s);
    vector<long> bottom;
    bottom.push_back(0);
    for(long i=0;i<n;i++) {
        scanf("%ld", &(h[i]));
        if(i>0 && h[i]<h[i-1]) bottom.push_back(i);
    }
    prepare(n);
    while(q--) {
        scanf("%ld %ld", &x, &y);
        l = (x + s*last - 1)%n;
        r = (y + s*last - 1)%n;
        if(l > r) swap(l, r);
        last = find(l, r);
        auto it = upper_bound(bottom.begin(), bottom.end(), l);
        if(it != bottom.end()) {
            last = max(last, cal(bottom, it-bottom.begin(), r));
        }
        printf("%ld\n", last);
    }
    return 0;
}
