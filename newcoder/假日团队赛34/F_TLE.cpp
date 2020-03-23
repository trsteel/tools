#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int main(){
    long long n, m, q, u, v, t;
    cin>>n>>m>>q>>u>>v>>t;
    priority_queue<long long> pq;
    long long num, val, left;
    for(long long i=0;i<n;i++) {
        cin>>num; pq.push(num);
    }
    for(long long i=0;i<m;i++) {
        val = pq.top() + q*i; pq.pop();
        if((i+1)%t==0) printf("%lld ", val);
        left = val*u/v;
        pq.push(left-q*i-q);
        pq.push(val-left-q*i-q);
    }
    cout<<endl;
    while(!pq.empty()) {
        for(int i=1;i<t;i++) pq.pop();
        val = pq.top(); pq.pop();
        printf("%lld ", val+q*m);
    }
    cout<<endl;
    return 0;
}