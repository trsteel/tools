#include <iostream>
#include <queue>
using namespace std;

int main(){
    long t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        priority_queue<long> pq;
        long ans = 0;
        for(char c: s) {
            if(c=='1') ans++;
            else if(ans > 0) {
                pq.push(ans);
                ans = 0;
            }
        }
        if(ans > 0) pq.push(ans);
        long res = 0;
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
            if(!pq.empty()) pq.pop();
        }
        cout<<res<<endl;
    }
    return 0;
}