#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const long long maxn = 200001;
long long t, n, m, x;
vector<long long> gl[maxn], gr[maxn];
unordered_map<long long, long long> cnt;

long long solve1() {
    return gl[0].size()*gr[0].size();
}

long long cal() {
    long long res = 0;
    unordered_set<long long> us;
    for(long long i=0;i<n;i++) {
        reverse(gl[i].begin(), gl[i].end());
        long long x = 0, y = 0, a = gl[i].size(), b = gr[i].size();
        while(x < a || y < b) {
            if(y==b || (x < a && gl[i][x]<gr[i][y])) {
                if(cnt[gl[i][x]]==1) {
                    res += b-y;
                } else {
                    res += a-x-1;
                    us.insert(gl[i][x]);
                }
                // cout<<i<<"a"<<res<<endl;
                x++;
            } else if(x==a || (y < b && gl[i][x]>gr[i][y])) {
                if(cnt[gr[i][y]]==1) {
                    res += a-x;
                } else {
                    res += b-y-1;
                    us.insert(gr[i][y]);
                }
                // cout<<i<<"b"<<res<<endl;
                y++;
            } else if(gl[i][x]==gr[i][y]){
                res += b-y-1 + a-x-1;
                us.insert(gr[i][y]);
                x++, y++;
                // cout<<i<<"c"<<res<<endl;
            }
        }
        // cout<<i<<" "<<res<<endl;
    }
    return res+us.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n; cnt.clear();
        for(int i=0;i<n;i++) {
            cin>>m;
            gl[i].clear(), gr[i].clear();
            for(int j=0;j<m;j++) {
                cin>>x;
                if(x < 0) gl[i].push_back(abs(x));
                else gr[i].push_back(x);
                cnt[abs(x)]++;
            }
        }
        // if(n==1) {
        //     cout<<solve1()<<" vs ";
        // }
        cout<<cal()<<endl;
    }
    return 0;
}