#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int main(){
    long n,m;
    cin>>n>>m;
    vector<vector<long>> vec(m, vector<long>(2,0));
    for(long i=0;i<m;i++)cin>>vec[i][0]>>vec[i][1];
    long ans = -1;
    for(vector<long> v:vec){
        long cur = 0;
        for(vector<long> v1:vec){
            cur+=abs(v1[0]-v[0])*v1[1];
        }
        if(ans==-1) ans = cur;
        else ans = min(ans, cur);
    }
    cout<<ans<<endl;
    return 0;
}
