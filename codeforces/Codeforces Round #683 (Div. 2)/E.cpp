#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long dfs(vector<long>& vec, int d) {
    if(vec.size()<=2) return vec.size();
    if(d<0) return 1;
    vector<long> v1, v2;
    for(long i: vec) {
        if(i&(1L<<d)) v1.push_back(i);
        else v2.push_back(i);
    }
    long a = dfs(v1, d-1), b = dfs(v2, d-1);
    long res = max(a, b);
    if(min(a, b)!=0) res++;
    return res;
}

int main(){
    long long n;
    cin>>n;
    vector<long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    cout<<(n-dfs(a, 30))<<endl;
    return 0;
}