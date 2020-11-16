// EXPLANATION: https://discuss.codechef.com/t/ddimmst-editorial/79385
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int>& parent, int x) {
    if(parent[x]==x||parent[x]==-1) return parent[x] = x;
    return parent[x] = find(parent, parent[x]);
}

int main() {
    int n, d;
    cin>>n>>d;
    vector<vector<int>> points(n, vector<int>(d));
    for(int i=0;i<n;i++) for(int j=0;j<d;j++) cin>>points[i][j];
    vector<pair<int, pair<int, int>>> edges;
    auto add_edge = [&d, &points, &edges](int u, int v) {
        int sum = 0;
        for(int i=0;i<d;i++) sum += abs(points[u][i]-points[v][i]);
        edges.push_back({sum, {u, v}});
    };
    for(int mask=0; mask<(1<<d); mask++) {
        vector<pair<int, int>> vec;
        for(int i=0;i<n;i++) {
            int sum = 0;
            for(int j=0;j<d;j++) {
                sum += ((mask>>j)&1) ? points[i][j] : -points[i][j];
            }
            vec.push_back({sum, i});
        }
        // cout<<mask<<" "<<vec.size()<<endl;
        int s = min_element(vec.begin(), vec.end())->second;
        int t = max_element(vec.begin(), vec.end())->second;
        for(int i=0;i<n;i++) { add_edge(s, i); add_edge(t, i); }
    }
    // cout<<edges.size()<<endl;
    sort(edges.rbegin(), edges.rend());
    vector<int> parent(n, -1);
    long long ans = 0;
    for(auto& e : edges) {
        int a = find(parent, e.second.first);
        int b = find(parent, e.second.second);
        if(a != b) { parent[a] = b; ans += e.first; }
    }
    cout<<ans<<endl;
    return 0;
}