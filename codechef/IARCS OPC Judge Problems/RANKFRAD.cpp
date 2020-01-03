#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int> > grid(n, vector<int>(n, false));
    int m, num;
    vector<int> idx(n);
    for(int i=0;i<n;i++) {
        cin>>m; 
        while(m--) {
            cin>>num;
            grid[i][num-1] = true;
        }
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&grid](int i, int j){
        return grid[i][j];
    });
    bool valid = true;
    for(int i=0;i<n-1;i++) {
        if(!grid[idx[i]][idx[i+1]]) {
            valid = false; break;
        }
    }
    if(valid) {
        cout<<"YES"<<endl;
        for(int i: idx) cout<<(i+1)<<" ";
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}