#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    long t, n, T, a[100001], p[100001];
    cin>>t;
    while(t--) {
        cin>>n>>T;
        for(int i=0;i<n;i++) {
            cin>>a[i]; p[i] = 0;
        }
        unordered_set<long> us;
        for(int i=0;i<n;i++) {
            if(us.count(T-a[i])) p[i] = 1;
            else us.insert(a[i]);
        }
        if(T%2==0) {
            long cnt = 0, x = T/2;
            for(int i=0;i<n;i++) if(a[i]==x) {
                p[i] = (cnt++)%2;
            }
        }
        for(int i=0;i<n;i++) cout<<p[i]<<" ";
        cout<<endl;
    }
    return 0;
}