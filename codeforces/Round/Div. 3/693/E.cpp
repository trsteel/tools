#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long maxn = 200005;
long long t, n, h, w, id;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        vector<vector<long> > vec(2*n, vector<long>(3));
        for(int i=0;i<n;i++) {
            cin>>h>>w;
            vec[2*i][0] = h, vec[2*i][1] = -w, vec[2*i][2] = i;
            vec[2*i+1][0] = w, vec[2*i+1][1] = -h, vec[2*i+1][2] = i;
        }
        sort(vec.begin(), vec.end());
        long e = -1, m = 2e9;
        vector<long> res(n, -1);
        for(auto& v: vec) {
            w = v[0], h = -v[1], id = v[2];
            if(h > m) res[id] = e+1;
            else if(h<m) {
                m = h, e = id;
            }
        }
        for(long i: res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}