#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const long maxn = 201;

long t, n, k, a[maxn], b[maxn];


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int x = a[0]+b[0];
        a[0] += b[0];
        sort(a, a+n);
        reverse(a, a+n);
        cout<<(a[k-1]<=x?"Yes":"No")<<endl;
    }
    return 0;
}