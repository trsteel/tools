#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool valid(unordered_set<int>& us, vector<int>& vec, int x) {
    if(us.count(x)) return false;
    int sum = x;
    for(int i=vec.size()-1;i>=0;i--) {
        sum += vec[i];
        if(us.count(sum)) return false;
    }
    return true;
}

int main(){
    int n; cin>>n;
    int ans = 1;
    unordered_set<int> us;
    vector<int> vec;
    for(int i=0;i<n;i++) {
        while(!valid(us, vec, ans)) ans++;
        vec.push_back(ans);
        int sum = 0;
        for(int i=vec.size()-1;i>=0;i--) {
            sum += vec[i];
            us.insert(sum);
        }
    }
    for(int i: vec) cout<<i<<" ";
    cout<<endl;
    return 0;
}