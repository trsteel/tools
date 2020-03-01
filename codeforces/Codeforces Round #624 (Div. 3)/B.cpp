#include <iostream>
#include <vector>
using namespace std;

bool match(vector<int>& vec) {
    for(int i=1;i<vec.size();i++) if(vec[i-1]>vec[i]) return false;
    return true;
}

bool cal(vector<int>& vec, vector<bool>& valid) {
    int n = vec.size();
    while(!match(vec)) {
        for(int i=1; i<n;i++) {
            if(vec[i-1]>vec[i]) {
                if(!valid[i-1]) return false;
                swap(vec[i-1], vec[i]);
            }
        }
    }
    return true;
}

int main(){
    int t, n, m, num; cin>>t;
    while(t--) {
        cin>>n>>m;
        vector<int> vec(n);
        vector<bool> valid(n, false);
        for(int i=0;i<n;i++) cin>>vec[i];
        for(int i=0;i<m;i++) {cin>>num; valid[num-1]=true;}
        cout<<(cal(vec, valid)?"YES":"NO")<<endl;
    }
    return 0;
}