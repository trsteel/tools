#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

int main(){
    long n, num, ans; cin>>n;
    unordered_set<long> us;
    int res = -1;
    for(long i=0;i<n;i++) {
        cin>>num;
        ans = sqrt(num);
        if(ans*ans==num) res = 1;
        if(us.find(num)!=us.end()) {
            if(res!=1) res = 2;
        }
        us.insert(num);
    }
    if(res!=-1) {
        cout<<res<<endl; return 0;
    }
    
    return 0;
}