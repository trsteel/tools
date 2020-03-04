#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long find(unordered_map<long long, int>& um, long long ans, int m) {
    long long res = ans+1;
    if(m > 0) {
        while(um.find(res)==um.end() || um[res]>m) res++;
    } else {
        while(um.find(res)!=um.end()) res++;
    }
    return res;
}

int main(){
    long long n, m; cin>>n>>m;
    vector<long long> vec(n);
    vec[0] = 1, vec[1] = 2;
    unordered_map<long long, int> um;
    um[3]++;
    for(int i=2; i<n; i++) {
        vec[i] = find(um, vec[i-1], m);
        if(m>0) m -= um[vec[i]];
        for(int j=0; j<i; j++) {
            um[vec[j]+vec[i]]++;
        }
    }
    if(m>0) {cout<<-1<<endl; return 0;}
    for(long long i: vec) cout<<i<<" ";
    cout<<endl; 
    return 0;
}