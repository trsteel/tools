#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long t, x;
const long long maxn = 40001, maxx = 1e9 + 7;
vector<long long> comb[maxn];

void init() {
    for(int i=1;i<maxn;i++) for(int j=0;j<=i/2;j++) {
        if(j==0) {comb[i].push_back(1); continue;}
        if(comb[i-1].size() <= j || comb[i-1].size()<=j-1) {
            continue;
        }
        if(comb[i-1][j]+comb[i-1][j-1]>maxx) break;
        comb[i].push_back(comb[i-1][j]+comb[i-1][j-1]);
    }
}

long long combine(long long n, long long k) {
    if(n==0) return 0;
    if(n-k < k) k = n - k;
    if(comb[n].size()<=k) return maxx;
    return comb[n][k];
}

long long find(long long b, long long ra) {
    long long la = b;
    if(ra >= maxn) ra = maxn-1;
    while(la <= ra) {
        long long mid = (la+ra)/2;
        long long ans = combine(mid, b);
        if(ans==x) return mid;
        if(ans > x) ra = mid - 1;
        else la = mid + 1;
    }
    return -1;
}

void cal() {
    if(x==1) {
        cout<<0<<" "<<0<<endl;
        return;
    }
    long long n = x, k = 1;
    for(int b=2;b+b<n+k&&b<101;b++) {
        long long a = find(b, n+k-b);
        if(a != -1 && a+b<n+k) {
            n = a, k = b;
        }
    }
    cout<<n<<" "<<k<<endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();
    cin>>t;
    while(t--) {
        cin>>x;
        cal();
    }
    return 0;
}