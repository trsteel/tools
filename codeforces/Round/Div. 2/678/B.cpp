#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<int> primes;

void pre(int n) {
    vector<bool> vis(n+1, false);
    for(int i=2;i<=sqrt(n);i++) if(!vis[i]) {
        primes.insert(i);
        for(int j=i;j<=n;j+=i) vis[j]=true;
    }
}

int main() {
    pre(1000);
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> vec(n, 0);
        for(int i=0;i<3&&i<n;i++) vec[i] = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<vec[(i+j)%vec.size()]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
