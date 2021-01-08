#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<pair<long, long> > path;
        for(long i=3;i<n;i++) {
            if(i==8 || i==64) continue;
            path.push_back(make_pair(i, i+1));
        }
        if(n>64) {
            long m = n;
            while(m>1) {
                m = m/64 + (m%64>0);
                path.push_back(make_pair(n, 64));
            }
            path.push_back(make_pair(64, 8));
            path.push_back(make_pair(64, 8));
            path.push_back(make_pair(8, 2));
            path.push_back(make_pair(8, 2));
            path.push_back(make_pair(8, 2));
        } else if(n > 8) {
            long m = n;
            while(m>1) {
                m = m/8 + (m%8>0);
                path.push_back(make_pair(n, 8));
            }
            path.push_back(make_pair(8, 2));
            path.push_back(make_pair(8, 2));
            path.push_back(make_pair(8, 2));
        } else if(n > 2) {
            long m = n;
            while(m>1) {
                m = m/2 + (m%2>0);
                path.push_back(make_pair(n, 2));
            }
        }
        cout<<path.size()<<endl;
        for(auto& p: path) {
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
    return 0;
}