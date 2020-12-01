#include <iostream>
#include <vector>
using namespace std;

const long maxn = 200001;
long long w[maxn];

int main(){
    long long t, n, W;
    cin>>t;
    while(t--) {
        cin>>n>>W;
        for(int i=1;i<=n;i++) cin>>w[i];
        vector<int> vec;
        long long sum = 0, l = (W+1)/2;
        bool find = false;
        for(int i=1;i<=n;i++) {
            if(w[i] > W) continue;
            if(w[i] >= l) {
                cout<<1<<endl<<i<<endl;
                find = true; break;
            }
            sum += w[i];
            vec.push_back(i);
            if(sum >= l) break;
        }
        if(!find) {
            if(sum < l) {cout<<-1<<endl; continue;}
            cout<<vec.size()<<endl;
            for(int i: vec) cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}