#include <iostream>
#include <vector>
using namespace std;

vector<long long> solve(long long n, long long m) {
    vector<long long> res;
    if(n>m) return res;
    if(n==m) {res.push_back(n); return res;}
    if((m-n)%2==0) {
        long long a=n, b = (m-n)>>1;
        if(a==0) {
            res.push_back(b);
            res.push_back(b);
            return res;
        }
        if((a^b)==a+b) {
            res.push_back(a+b);
            res.push_back(b);
            return res;
        }
        res.push_back(a);
        res.push_back(b);
        res.push_back(b);
        return res;
    }
    return res;
}

int main(){
    long long n, m; cin>>n>>m;
    if(n==0&&m==0) {
        cout<<0<<endl; return 0;
    }
    auto res = solve(n, m);
    if(res.empty()) {
        cout<<-1<<endl; return 0;
    }
    cout<<res.size()<<endl;
    for(long long i: res) cout<<i<<" ";
    cout<<endl;
    return 0;
}