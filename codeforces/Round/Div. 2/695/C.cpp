#include <iostream>
#include <algorithm>
using namespace std;
const long long maxn = 300001;
long long n[3], a[3][maxn], sum[3];

long long cal(long long i, long long j) {
    long long res = 0;
    res = sum[j]-a[j][0]-a[i][0] + sum[i]-a[i][0]-a[j][0];
    res = max(res, abs(sum[i]-sum[j]));
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n[0]>>n[1]>>n[2];
    for(long long i=0;i<3;i++) {
        sum[i] = 0;
        for(long long j=0;j<n[i];j++) {
            cin>>a[i][j];
            sum[i]+=a[i][j];
        }
        sort(a[i], a[i]+n[i]);
    }
    long long res = 0;
    res = max(res, sum[0]+max(cal(1,2), cal(2,1)));
    res = max(res, sum[1]+max(cal(0,2), cal(2,0)));
    res = max(res, sum[2]+max(cal(1,0), cal(0,1)));
    cout<<res<<endl;
    return 0;
}