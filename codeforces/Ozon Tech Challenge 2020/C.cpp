#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, num; cin>>n>>m;
    vector<long long> vec(n, 0);
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(), vec.end());
    vector<int> mod(m, 0);
    long long res = 1;
    for(int i=0; i<n; i++) {
        if(i>0 && vec[i-1]==vec[i]) {res = 0; break;}
        int ans = vec[i]%m;
        for(int i=0;i<m;i++) {
            if(mod[i]==0) continue;
            res = res*mod[i]*(m+ans-i)%m;
            if (res==0) res = m;
        }
        mod[ans]++;
    }
    cout<<(res%m)<<endl;
    return 0;
}