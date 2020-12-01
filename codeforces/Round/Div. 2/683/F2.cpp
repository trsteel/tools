#include <iostream>
#include <vector>
using namespace std;


int main(){
    long long n, bound = 448;
    cin>>n;
    vector<long> a(n), cnt(200001, 0);
    long freq = 0, dup = 0, num = -1, maxa = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i]; cnt[a[i]]++;
        maxa = max(maxa, a[i]);
        if(cnt[a[i]] > freq) freq = cnt[a[i]], dup = 1, num = a[i];
        else if(cnt[a[i]]==freq) dup++;
    }
    if(dup > 1) {
        cout<<n<<endl; return 0;
    }
    long ans = 0;
    for(int k=1; k<=maxa; k++) if(k != num && cnt[k] > bound) {
        vector<long> pos((n+1)*2, -1);
        long now = 0;
        for(long i=0;i<n;i++) {
            if(a[i]==k) now--;
            else if(a[i]==num) now++;
            if(now && pos[now+n+1]==-1) pos[now+n+1] = i;
            ans = max(ans, i-pos[now+n+1]);
        }
    }
    vector<int> mp(200001, 0);
    for(freq = 1; freq <= bound; freq++) {
        for(long i=1;i<=maxa;i++) cnt[i] = 0;
        for(long i=0;i<=n;i++) mp[i] = 0;
        long l = 0;
        for(long r=0;r<n;r++) {
            mp[cnt[a[r]]]--;
            cnt[a[r]]++;
            mp[cnt[a[r]]]++;
            while(cnt[a[r]] > freq) {
                mp[cnt[a[l]]]--;
                cnt[a[l]]--;
                mp[cnt[a[l]]]++;
                l++;
            }
            if(mp[freq] >= 2) ans = max(ans, r-l+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}