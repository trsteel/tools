#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    long t, n, m, a;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        unordered_set<long> us;
        for(int i=0;i<n;i++) {
            cin>>a; us.insert(a);
        }
        long res = 0;
        for(int i=0;i<m;i++) {
            cin>>a; res += us.count(a);
        }
        cout<<res<<endl;
    }
    return 0;
}