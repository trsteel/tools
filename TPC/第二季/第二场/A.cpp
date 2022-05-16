#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const long maxn = 101;

long t, n, k, a[maxn];

void cal() {
    vector<int> r1(n), r2(n), r3(n);
    int idx = a[0], cnt = 0;
    for(int i=0;i<n;i++) {
        if(idx==a[i]) cnt++;
        else idx = a[i], cnt = 1;
        r1[i] = cnt;
        if(cnt >= k) {
            cout<<(i+1)<<" "<<a[i]<<endl; return;
        }
    }
    for(int i=0;i<n;i++) {
        if(idx==a[i]) cnt++;
        else idx = a[i], cnt = 1;
        r2[i] = cnt;
        if(cnt >= k) {
            cout<<(n+i+1)<<" "<<a[i]<<endl; return;
        }
    }
    for(int i=0;i<n;i++) {
        if(idx==a[i]) cnt++;
        else idx = a[i], cnt = 1;
        r3[i] = cnt;
        if(cnt >= k) {
            cout<<(2*n+i+1)<<" "<<a[i]<<endl; return;
        }
    }
    int id = -1, round = -1;
    for(int i=0;i<n;i++) if(r2[i] < r3[i]) {
        int d = r3[i] - r2[i];
        if((k-r3[i])%d==0) {
            int r = (k-r3[i])/d*n+2*n+i+1;
            if(round == -1 || r < round) {
                id = a[i], round = r;
            }
        }
    }
    if(id==-1) {
        cout<<"INF"<<endl; return;
    } else {
        cout<<round<<" "<<id<<endl; return;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        cal();
    }
    return 0;
}