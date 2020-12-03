#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string.h>
#include <limits.h>
using namespace std;

const long maxn = 1e5 + 3;
long dis[maxn], x[maxn], y[maxn];
priority_queue<pair<long, long>, vector<pair<long, long>>, greater< > > qu;

void solve(long u, long v) {
    long d = dis[u] + min(abs(x[u]-x[v]), abs(y[u]-y[v]));
    if(dis[v] > d) {dis[v] = d; qu.push({d, v});}
}

int main() {
    long n, m, fx, fy;
    cin>>n>>m>>x[0]>>y[0]>>fx>>fy;
    set<pair<long, long>> r, c;
    for(int i=1;i<=m;i++) {
        cin>>x[i]>>y[i];
        r.insert({x[i], i});
        c.insert({y[i], i});
    }
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[0] = 0;
    qu.push({0, 0});
    while(!qu.empty()) {
        auto p = qu.top(); qu.pop();
        long d = p.first, u = p.second;
        if(dis[u] != d) continue;
        r.erase({x[u], u});
        c.erase({y[u], u});
        auto it = r.lower_bound({x[u], 0});
        if(it != r.end()) solve(u, it->second);
        if(it != r.begin()) solve(u, (--it)->second);
        it = c.lower_bound({y[u], 0});
        if(it != c.end()) solve(u, it->second);
        if(it != c.begin()) solve(u, (--it)->second);
    }
    long ans = INT_MAX;
    for(int i=0;i<=m;i++) ans = min(ans, dis[i] + abs(x[i]-fx) + abs(y[i]-fy));
    cout<<ans<<endl;
    return 0;
}
