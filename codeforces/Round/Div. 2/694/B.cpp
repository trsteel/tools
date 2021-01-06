#include <iostream>
#include <queue>
using namespace std;

int main(){
    long long t, n, x, a;
    cin>>t;
    while(t--) {
        cin>>n>>x;
        queue<pair<long long, long long> > qu;
        long long sum = 0;
        for(int i=0;i<n;i++) {
            cin>>a; qu.push(make_pair(a, 1));
            sum += a;
        }
        while(!qu.empty()) {
            auto p = qu.front(); qu.pop();
            if(p.first%x) break;
            sum += p.first*p.second;
            qu.push(make_pair(p.first/x, x*p.second));
        }
        cout<<sum<<endl;
    }
    return 0;
}