#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

bool cal1(vector<long>& a, vector<long>& b, long n) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a[0]>=b[0]) return false;
    unordered_set<long> us;
    us.insert(a[0]);
    us.insert(b[0]);
    for(long i=1;i<n;i++) {
        if(us.count(a[i])==0) return false;
        if(a[i]>=b[i]) return false;
        us.insert(a[i]);
        us.insert(b[i]);
    }
    return true;
}

bool cal(vector<long>& a, vector<long>& b, long n, long s) {
    if(s==1) return cal1(a, b, n);
    if(n==1) return a[0]<b[0];
    vector<long> vec(a.begin(), a.end());
    vec.insert(vec.end(), b.begin(), b.end());
    sort(vec.begin(), vec.end());
    for(long i=0;i<n;i++) if(vec[i]>=vec[i+n]) return false;
    return true;
}

int main(){
    long t, s, n; cin>>t>>s;
    while(t--) {
        cin>>n;
        vector<long> a(n), b(n);
        for(long& i: a) cin>>i;
        for(long& i: b) cin>>i;
        cout<<(cal(a, b, n, s)?"YES":"NO")<<endl;
    }
    return 0;
}