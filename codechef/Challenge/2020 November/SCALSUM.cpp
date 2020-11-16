#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stdio.h>
using namespace std;

const long maxn = 300001;
unsigned int w[maxn], mut[maxn], parent[maxn], depth[maxn];
vector<int> adj[maxn];
unordered_map<long, unsigned int> cache;

unsigned int cal(int u, int v) {
    if(u==v) return mut[u];
    // 优化点：隔几层添加记忆搜索，避免频繁查cache
    if(depth[u]&127) {
        return w[u]*w[v] + cal(parent[u], parent[v]);
    }
    long key = u > v ? (u * maxn + v) : (v * maxn + u);
    if(cache.count(key)) return cache[key];
    return cache[key] = w[u]*w[v] + cal(parent[u], parent[v]);
}

int main() {
    cache.reserve(1e8);
    cache.rehash(1e8);
    int n, q, u, v;
    scanf("%d %d", &n, &q);
    for(int i=1;i<=n;i++) scanf("%u", &(w[i]));
    for(int i=0;i<n-1;i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 查找父子关系
    queue<int> qu;
    qu.push(1);
    mut[0] = 0, parent[1] = 0, depth[1] = 0;
    while(!qu.empty()) {
        int x = qu.front(); qu.pop();
        mut[x] = w[x]*w[x] + mut[parent[x]];
        for(int y: adj[x]) if(y!=parent[x]) {
            parent[y] = x; qu.push(y);
            depth[y] = depth[x] + 1;
        }
    }
    while(q--) {
        scanf("%d %d", &u, &v);
        printf("%u\n", cal(u, v));
    }
    return 0;
}
