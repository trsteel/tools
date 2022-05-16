#include <iostream>

using namespace std;

int main() {
    long t, n, x;
    cin>>t;
    while(t--) {
        cin>>n;
        long ng = 0, zo = 0, ps = 0;
        for(long i=0;i<n;i++) {
            cin>>x;
            if(x<0) ng++;
            else if(x==0) zo++;
            else ps++;
        }
        if(ng < ps) {
            cout<<(ps <= ng+zo+1 ? "Yes": "No");
        } else if (ng > ps) {
            cout<<(ng <= ps+zo+1 ? "Yes": "No");
        } else cout<<"Yes";
        if (t > 0) cout<<endl;
    }
    return 0;
}