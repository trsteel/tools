#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int>& parent, int x) {
    if(parent[x] == x || parent[x] == -1) return parent[x] = x;
    return parent[x] = find(parent, parent[x]);
} 

int cal(vector<vector<int> >& roads, int n) {
    sort(roads.begin(), roads.end(), [](vector<int>& v1, vector<int>& v2){
        return v1[2] < v2[2];
    });
    vector<int> parent(n, -1);
    int res = 0;
    for(auto& v: roads) {
        int a = find(parent, v[0]), b = find(parent, v[1]);
        if(a==b) continue;
        parent[a] = b;
        res += v[2];
    }
    return res;
}

int main(){
    int n; cin>>n;
    vector<vector<int> > roads;
    roads.reserve((n-1)*(n-1)/2);
    int num;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>num;
            if(i>0 && j>i) roads.push_back({i, j, num});
        }
    }
    cout<<cal(roads, n)<<endl;
    return 0;
}