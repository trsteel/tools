
#include <iostream>
#include <set>
using namespace std;

int main(){
    long n, x, t, num; cin>>t;
    while(t--) {
        cin>>n>>x;
        set<long> st;
        for(long i=0;i<n;i++) {
            cin>>num; st.insert(num);
        }
        long pre = 0, res = 0;
        for(long i: st) {
            long d = i-pre-1;
            // cout<<i<<" "<<d<<" "<<x<<endl;
            if(d>x) {
                res = pre+x; x=0; break;
            }
            res = i; x-=d; pre = i;
        }
        if(x>0) res+=x;
        cout<<res<<endl;
    }
    return 0;
}