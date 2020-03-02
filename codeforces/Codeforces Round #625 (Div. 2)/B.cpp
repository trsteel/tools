#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
using namespace std;

int main(){
    long n; cin>>n;
    vector<long> vec(n);
    map<long, long long> um;
    long long res = 0;
    for(long i=0;i<n;i++) {
        cin>>vec[i]; 
        um[vec[i]-i] += vec[i];
        res = max(res, um[vec[i]-i]);
    }
    cout<<res<<endl;
    return 0;
}