#include <iostream>
#include <vector>
using namespace std;

bool move(vector<int>& src, vector<int>& dst, int d) {
    int n = src.size();
    for(int i=0;i<n;i++) {
        int j = (i-d+n)%n;
        if(src[j]!=dst[i]) return false;
    }
    return true;
}

 vector<int> valid(vector<vector<int> >& src, vector<vector<int> >& dst, int col, int d) {
    int n = src.size();
    vector<int> res;
    for(int i=0;i<n;i++) {
        int j = (i+d+n)%n;
        // cout<<i<<j<<col<<d<<endl;
        swap(src[i][col], src[j][col]);
        bool valid = false;
        for(int k=0; k<n; k++) {
            if(move(src[i], dst[i], k)) {
                for(int x=0;x<k;x++) res.push_back(i+1);
                valid = true; break;
            } else if(move(src[i], dst[i], -k)) {
                for(int x=0;x<k;x++) res.push_back(-i-1);
                valid = true; break;
            }
        }
        swap(src[i][col], src[j][col]);
        if(!valid) return {};
    }
    res.insert(res.begin(), d*(col+1));
    return res;
}

vector<int> cal(vector<vector<int> >& src, vector<vector<int> >& dst) {
    int n = src.size();
    vector<int> res;
    for(int i=0;i<n;i++) {
        res = valid(src, dst, i, 1);
        if(!res.empty()) return res;
        res = valid(src, dst, i, -1);
        if(!res.empty()) return res;
    }
    return res;
}

int main(){
    int n; cin>>n;
    vector<vector<int> > src(n, vector<int>(n)), dst(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>src[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>dst[i][j];
    auto res = cal(src, dst);
    cout<<(res.empty()?"NO":"YES")<<endl;
    if (!res.empty()) {
        cout<<res.size();
        for(int i: res) cout<<" "<<i;
    }
    return 0;
}