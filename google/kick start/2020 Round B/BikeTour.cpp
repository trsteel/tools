#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long nums[101];

int main(){
    long t, n; cin>>t;
    for(long tt=1;tt<=t;tt++) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>nums[i];
        int res = 0;
        for(int i=1;i<n-1;i++) {
            if(nums[i-1]<nums[i]&&nums[i]>nums[i+1]) res++;
        }
        cout<<"Case #"<<tt<<": "<<res<<endl;
    }
    return 0;
}