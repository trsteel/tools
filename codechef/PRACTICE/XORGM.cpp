/**
 * 关键点: 注意N是奇数，则A和B数组所有数字的异或值==任一A[i]^C[i]
 **/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int decode_xor(int x, int a) {
    int b = 0;
    for(int i=0;i<32;i++) {
        if((x&(1<<i))>0) {
            if((a&(1<<i))==0) b |= 1<<i;
        } else {
            if((a&(1<<i))>0) b |= 1<<i;
        }
    }
    return b;
}

bool process(vector<int>& a, vector<int>& um, int x) {
    vector<int> cnt(um.size(), 0), res(a.size());
    for(int i=0;i<a.size();i++) {
        res[i] = decode_xor(x, a[i]);
        if(++cnt[res[i]]>um[res[i]]) return false;
    }
    for(int i: res) cout<<i<<" ";
    return true;
}

int main(){
    int t, n, num; cin>>t;
    while(t--) {
        cin>>n;
        vector<int> a(n);
        vector<int> um(1e6+1, 0);
        int s = 0;
        for(int i=0;i<n;i++) {cin>>a[i]; s^=a[i];}
        for(int i=0;i<n;i++) {cin>>num; um[num]++; s^=num;}
        if(!process(a, um, s)) cout<<-1;
        cout<<endl;
    }
    return 0;
}