#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long long t, n, a[200001];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        vector<long long> vec;
        long long sum = 0;
        for(int i=1;i<n;i++) {
            long long x = abs(a[i]-a[i-1]);
            sum += x, vec.push_back(x);
        }
        long long res = sum;
        res = min(res, sum-vec[0]);
        res = min(res, sum-vec.back());
        for(int i=1;i<n-1;i++) {
            res = min(res, sum + abs(a[i+1]-a[i-1]) - vec[i-1] - vec[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}