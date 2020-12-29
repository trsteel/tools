#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    long long t, n;
    string s;
    cin>>t;
    while(t--) {
        cin>>n>>s;
        unordered_map<long long, long long> um;
        um[0]++;
        long long ans = 0;
        for(char c: s) {
            ans += long(c - '0') - 1;
            um[ans]++;
        }
        long long res = 0;
        for(auto& it: um) {
            // cout<<it.first<<" "<<it.second<<endl;
            res += it.second*(it.second-1)/2;
        }
        cout<<res<<endl;
    }
    return 0;
}