#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    long t, n, a;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<long> cnt(1001, 0);
        long ma = 0;
        for(int i=0;i<n;i++) {
            cin>>a; cnt[a]++;
            ma = max(ma, a);
        }
        vector<long> res;
        while(cnt[ma]--) res.push_back(ma);
        while(res.size()<n) {
            bool find = false;
            for(long i=2; i < ma; i++) if(ma%i==0) {
                long k = ma/i;
                for(long j = k; j <= 1000; j+=k) {
                    while(cnt[j]>0) {
                        find = true;
                        res.push_back(j);
                        cnt[j]--;
                    }
                }
                if(find) {
                    ma = k; break;
                }
            }
            if(!find) break;
        }
        for(int i=0;i<cnt.size();i++) if(cnt[i] > 0) {
            while(cnt[i]--) res.push_back(i);
        }
        for(long i: res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}