#include <iostream>
#include <vector>
using namespace std;


int main(){
    long long n;
    cin>>n;
    vector<long> a(n), cnt(101, 0);
    long freq = 0, dup = 0, num = -1;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] > freq) freq = cnt[a[i]], dup = 1, num = a[i];
        else if(cnt[a[i]]==freq) dup++;
    }
    if(dup > 1) {
        cout<<n<<endl; return 0;
    }
    long ans = 0;
    for(int k=1; k<=100; k++) if(k != num) {
            vector<long> pos((n+1)*2, -1);
            long now = 0;
            for(long i=0;i<n;i++) {
                if(a[i]==k) now--;
                else if(a[i]==num) now++;
                if(now && pos[now+n+1]==-1) pos[now+n+1] = i;
                ans = max(ans, i-pos[now+n+1]);
            }
        }
    cout<<ans<<endl;
    return 0;
}