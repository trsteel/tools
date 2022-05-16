#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const long maxn = 1e5 + 1;
const long maxa = 1e3 + 1;

long t, n, a[maxn], cnt[maxa];
bool vis[maxa];

bool check(long num) {
    for(int i=1;i<num;i++) {
        if(i+i!=num && !vis[i] && !vis[num-i]) return true;
    }
    return false;
}

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        vector<long> dup;
        for(long i=0;i<n;i++) {
            cin>>a[i]; 
            if(++cnt[a[i]]==2) dup.push_back(a[i]);
        }
        long res = 0;
        if(dup.size() == 1 && cnt[dup[0]]==2) {
            for(long i=0;i<n;i++) vis[a[i]] = true;
            if(check(dup[0])) res = 2;
        } else if(dup.size()==0) {
            sort(a, a+n);
            for(long i=0;i<n;i++) {
                if(check(a[i])) res++;
                vis[a[i]] = true;
            }
        }
        cout<<res;
        if(t>0) cout<<endl;
    }
    return 0;
}