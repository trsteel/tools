#include <iostream>
#include <string.h>
using namespace std;

long vis[26];

int main(){
    long t, n, k; cin>>t;
    string s;
    while(t--) {
        cin>>n>>k>>s;
        long res = 0;
        for(long i=0;i<(k+1)/2;i++) {
            memset(vis, 0, sizeof(vis));
            long sum=0, ma = 0;
            for(long j=0;j<n;j+=k) {
                ma = max(ma, ++vis[s[j+i]-'a']);
                sum++;
                if(k-1-i!=i) {
                    ma = max(ma, ++vis[s[j+k-1-i]-'a']);
                    sum++;
                }
            }
            // cout<<i<<sum<<ma<<endl;
            res += sum - ma;
        }
        cout<<res<<endl;
    }
    return 0;
}