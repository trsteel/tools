#include <iostream>
#include <limits.h>
#include <string.h>
#include <vector>
using namespace std;
const long maxn = 200001;
long p[maxn], c[maxn];
bool vis[maxn];

int main(){
    long n, t; cin>>t;
    while(t--) {
        cin>>n;
        for(long i=0;i<n;i++) {cin>>p[i];p[i]--;}
        for(long i=0;i<n;i++) cin>>c[i];
        memset(vis, 0, sizeof(vis));
        long ans = INT_MAX;
        for(long i=0;i<n;i++) {
            if(vis[i]) continue;
            vector<long> vec;
            while(!vis[i]) {
                vec.push_back(c[i]);
                vis[i] = true, i = p[i];
            }
            for(long len=1;len<=vec.size();len++) {
                if(vec.size()%len) continue;
                for(long l=0; l<len; l++) {
                    bool valid = true;
                    for(long j=l;j<vec.size();j+=len)
                        if(vec[l] != vec[j]) valid = false;
                    if(valid) ans = min(ans, len);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}