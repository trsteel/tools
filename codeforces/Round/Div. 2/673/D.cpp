#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long t, n, a[10001];
    cin>>t;
    while(t--) {
        cin>>n;
        long long sum = 0;
        for(int i=1;i<=n;i++) {
            cin>>a[i]; sum += a[i];
        }
        if(sum % n) {
            cout<<-1<<endl; continue;
        }
        long long avg = sum / n;
        vector<vector<long>> vec;
        for(long i=2;i<=n;i++) {
            if(a[i]%i) vec.push_back({1, i, i-a[i]%i});
            long long d = (a[i]+i-1)/i;
            if(d > 0) vec.push_back({i, 1, d});
        }
        for(long i=2;i<=n;i++) {
            vec.push_back({1, i, avg});
        }
        cout<<vec.size()<<endl;
        for(auto& v: vec) {
            cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
        }
    }
    return 0;
}
