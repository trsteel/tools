#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long cal(vector<long long>& vec) {
    sort(vec.begin(), vec.end());
    int n = vec.size();
    long long avg = vec[n/2], ans = 0;
    for(long long l: vec) ans += abs(l-avg);
    long long avg1 = vec[n/2-1], ans1 = 0;
    for(long long l: vec) ans1 += abs(l-avg1);
    ans = min(ans, ans1);
    return ans;
}

int main() {
    long long t, n, m, a[101][101];
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(long long i=0;i<n;i++) for(long long j=0;j<m;j++) cin>>a[i][j];
        long long res = 0;
        for(long long i=0;i<n/2;i++) for(long long j=0;j<m/2;j++) {
            vector<long long> vec = {a[i][j], a[n-1-i][j], a[i][m-1-j], a[n-1-i][m-1-j]};
            res += cal(vec);
        }
        if(n&1) {
            for(long long j=0;j<m/2;j++) {
                vector<long long> vec = {a[n/2][j], a[n/2][m-1-j]};
                res += cal(vec);
            }
        }
        if(m&1) {
            for(long long i=0;i<n/2;i++) {
                vector<long long> vec = {a[i][m/2], a[n-1-i][m/2]};
                res += cal(vec);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
