#include <iostream>
#include <unordered_map>
using namespace std;
const long maxn = 100001;
long n, q, a;
char c;
unordered_map<long, long> cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a; cnt[a]++;
    }
    long sq = 0, rec = 0;
    for(auto& it: cnt) {
        sq += it.second/4;
        rec += (it.second%4)/2;
    }
    cin>>q;
    for(int i=0;i<q;i++) {
        cin>>c>>a;
        sq -= cnt[a]/4;
        rec -= (cnt[a]%4)/2;
        if(c=='+') cnt[a]++;
        else cnt[a]--;
        sq += cnt[a]/4;
        rec += (cnt[a]%4)/2;
        cout<<((sq>=2||(sq==1&&rec>=2))?"YES":"NO")<<endl;
    }
    return 0;
}