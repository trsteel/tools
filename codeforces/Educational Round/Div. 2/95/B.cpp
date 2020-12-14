#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long t, n, a[101], l[101];

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>l[i];
        vector<long long> vec;
        for(int i=0;i<n;i++) if(l[i]==0) vec.push_back(a[i]);
        if(!vec.empty()) sort(vec.begin(), vec.end());
        int idx = vec.size()-1;
        for(int i=0;i<n;i++) if(l[i]==0) a[i] = vec[idx--];
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}