#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const long maxn = 1001;
long nums[maxn], color[maxn], t, n;


bool check(long n) {
	for (long i = 2; i * i <= n; ++i) if (n % i == 0) return false;
	return true;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> idx(11, 0);
        long ans = 1;
        for(long i=0;i<n;i++) {
            cin>>nums[i];
        }
        memset(color, 0, sizeof(color));
        for(long j=2;j<maxn;j++) if(check(j)) {
            bool add = false;
            for(long k=0;k<n;k++) if(color[k]==0 && nums[k]%j==0) {
                color[k] = ans; add = true;
            }
            if(add) ans++;
        }
        cout<<(ans-1)<<endl;
        for(long i=0;i<n;i++) cout<<color[i]<<" ";
        cout<<endl;
    }
    return 0;
}