#include <iostream>
#include <algorithm>
using namespace std;
long long nums[100001];

int main(){
    long long t, n, x; cin>>t;
    while(t--) {
        cin>>n>>x;
        for(long long i=0;i<n;i++) cin>>nums[i];
        sort(nums, nums+n);
        long long sum = 0, res = 0;
        for(long long i=n-1;i>=0;i--) {
            if((res+1)*x>sum+nums[i]) break;
            res++;
            sum += nums[i];
        }
        cout<<res<<endl;
    }
    return 0;
}