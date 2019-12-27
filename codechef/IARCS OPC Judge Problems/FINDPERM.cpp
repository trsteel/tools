#include <iostream>
#include <vector>
using namespace std;

vector<int> cal(vector<int>& vec) {
    int n = vec.size();
    vector<int> res;
    res.reserve(n);
    for(int i=0;i<n;i++) {
        res.insert(res.end()-vec[i], i+1);
    }
    return res;
}
int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    auto res = cal(vec);
    for(int i: res) cout<<i<<" ";
    return 0;
}