#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long cal(vector<int>& vec) {
    int n = vec.size();
    unordered_map<int, int> m;
    for(int i: vec) m[i]++;
    long res = 0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int d = vec[i]+vec[j];
            if(d%2==1) continue;
            d >>= 1;
            if(m.find(d)!=m.end()) {
                res += m[d];
                m.erase(d);
            }
        }
    }
    return res;
}

int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    cout<<cal(vec)<<endl;
    return 0;
}