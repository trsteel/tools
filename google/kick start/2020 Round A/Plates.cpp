#include <iostream>
#include <vector>
using namespace std;

vector<vector<long> > cache;

long dfs(vector<vector<long> >& vec, long x, long p) {
    if(x==vec.size()||p==0) return 0;
    if(cache[x][p]>0) return cache[x][p];
    long k = vec[x].size(), res = dfs(vec, x+1, p), sum = 0;
    for(int i=0;i<p&&i<k;i++) {
        sum += vec[x][i];
        res = max(res, sum+dfs(vec, x+1, p-i-1));
    }
    return cache[x][p] = res;
}

int main(){
    long T, n, k, p; cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>k>>p;
        vector<vector<long> > vec(n, vector<long>(k));
        for(int i=0;i<n;i++) for(int j=0;j<k;j++) {
            cin>>vec[i][j];
        }
        cache = vector<vector<long> >(n, vector<long>(p+1, 0));
        cout<<"Case #"<<t<<": "<<dfs(vec, 0, p)<<endl;
    }
    return 0;
}