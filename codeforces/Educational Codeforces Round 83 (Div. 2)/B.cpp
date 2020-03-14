#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long t, n; cin>>t;
    while(t--) {
        cin>>n;
        vector<long> vec(n);
        for(long& i: vec) cin>>i;
        sort(vec.begin(), vec.end(), greater<int>());
        for(long i: vec) cout<<i<<" "; cout<<endl;
    }
    return 0;
}