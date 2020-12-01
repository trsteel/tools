#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    long t, n, x;
    cin>>t;
    while(t--) {
        cin>>n>>x;
        vector<long> a(n), b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        bool valid = true;
        for(int i=0;i<n;i++) {
            if(a[i]+b[i]>x) {valid = false; break;}
        }
        cout<<(valid?"YES":"NO")<<endl;
    }
    return 0;
}