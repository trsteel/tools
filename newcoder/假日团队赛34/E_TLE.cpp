#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    long n; cin>>n;
    vector<long> x(n);
    char c;
    for(int i=0;i<n;i++) {
        cin>>x[i]>>c;
        if(c=='S') x[i] = -x[i];
    }
    sort(x.begin(), x.end(), [](long i, long j){
        return abs(i) < abs(j);
    });
    unordered_map<long, long> um;
    long res = 0, ans = 0;
    for(int i=0;i<n;i++) {
        ans += x[i]<0?-1:1;
        for(auto& it: um) {
            if(ans>it.first&&(ans-it.first)%2==1) {
                res = max(res, abs(x[i])-it.second);
            }
        }
        if(um.find(ans)==um.end()) um[ans] = abs(x[i]);
    }
    cout<<res<<endl;
    return 0;
}