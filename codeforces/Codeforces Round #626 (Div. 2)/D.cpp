#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> vec(n);
    for(long long& i: vec) cin>>i;
    unordered_map<long long, long long> um;
    for(long long i: vec) um[i]++;
    vec.clear();
    long long res = 0;
    for(auto& it: um) {
        if(it.second%2==1) vec.push_back(it.first);
        long long ans = it.second*(it.second-1)/2;
        if(ans%2==1) res ^= 2*it.first;
    }
    for(int i=31;i>=0;i--) {
        bool zero = true;
        for(long long j: vec) {
            if(j&(1<<31)) zero = !zero;
        }
        if(!zero) res ^= 1<<i;
    }
    cout<<res<<endl;
    return 0;
}