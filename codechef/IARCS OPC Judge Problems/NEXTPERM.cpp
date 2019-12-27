#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cal(vector<int>& vec) {
    int n = vec.size();
    int ans = vec.back(), idx = n-1;
    while(idx>=0 && vec[idx]>=ans) {
        ans = vec[idx--];
    }
    if (idx < 0) {
        reverse(vec.begin(), vec.end());
        return;
    }
    // cout<<idx<<endl;
    ans = idx;
    for(int i=idx+1;i<=n;i++) {
        if(vec[i]>vec[idx] && (ans==idx || vec[i]<vec[ans])) ans = i;
    }
    swap(vec[idx], vec[ans]);
    sort(vec.begin()+idx+1, vec.end());
}

int main(){
    int n, k; cin>>k>>n;
    vector<int> nums(k);
    while(n--) {
        for(int i=0;i<k;i++) cin>>nums[i];
        cal(nums);
        for(int i: nums) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}