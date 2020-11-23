#include <iostream>
#include <vector>

using namespace std;

bool cal(string& a, string& b, int k) {
    vector<int> cnta(26, 0), cntb(26, 0);
    for(char c: a) cnta[c-'a']++;
    for(char c: b) cntb[c-'a']++;
    for(int i=0;i<25;i++) {
        if(cntb[i]>cnta[i]) return false;
        int d = cnta[i] - cntb[i];
        if(d % k) return false;
        cnta[i+1] += d;
    }
    return cnta[25] == cntb[25];
}

int main(){
    int t, n, k;
    cin>>t;
    string a, b;
    while(t--) {
        cin>>n>>k;
        cin>>a>>b;
        cout<<(cal(a, b, k)?"YES":"NO")<<endl;
    }
    return 0;
}