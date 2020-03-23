#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long t, n, b; cin>>t;
    for(long tt=1;tt<=t;tt++) {
        cin>>n>>b;
        vector<long> vec(n);
        for(long& i: vec) cin>>i;
        sort(vec.begin(), vec.end());
        long res = 0, sum = 0;
        for(long i: vec) {
            if(sum+i>b) break;
            sum += i; res++;
        }
        cout<<"Case #"<<tt<<": "<<res<<endl;
    }
    return 0;
}