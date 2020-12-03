#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long maxn = 200001;
long long seg[maxn];

void update(long long n, long long x, long long val) {
    while(x <= n) {seg[x] += val; x += x&(-x);}
}

long long query(long long x) {
    long long res = 0;
    while(x>0) {res += seg[x]; x -= x&(-x);}
    return res;
}

int main(){
    long long n; string s;
    cin>>n>>s;
    string t = s;
    reverse(t.begin(), t.end());
    vector<vector<long long>> vec(26);
    vector<long long> idx(26, 0);
    for(long long i=0;i<n;i++) vec[s[i]-'a'].push_back(i);
    for(long long i=0;i<n;i++) update(n, i+1, 1);
    long long res = 0;
    for(char c: t) {
        long long j = vec[c-'a'][idx[c-'a']++];
        res += query(j);
        update(n, j+1, -1);
    }
    cout<<res<<endl;
    return 0;
}