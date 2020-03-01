#include <iostream>
#include <vector>
using namespace std;

int cal(vector<int>& vec, int k) {
    vector<int> cnt(k+1, 0);
    int res = 1, l=0, ans=1;
    cnt[vec[0]]++;
    for(int i=1;i<vec.size();i++) {
        if(cnt[vec[i]]++==0) ans++;
        while(ans==k) {
            if(--cnt[vec[l++]]==0) ans--;
        }
        res = max(res, i-l+1);
    }
    return res;
}

int main(){
    int t, n, k; cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<int> vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        cout<<cal(vec, k)<<endl;
    }
    return 0;
}