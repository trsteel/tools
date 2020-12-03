#include <iostream>

using namespace std;

int main() {
    long t, n, m, a[2][2];
    cin>>t;
    while(t--) {
        cin>>n>>m;
        bool valid = false;
        while(n--) {
            for(int i=0;i<2;i++) for(int j=0;j<2;j++) cin>>a[i][j];
            if(a[1][0] == a[0][1]) valid = true;
        }
        if(m&1) valid = false;
        cout<<(valid ? "YES" : "NO")<<endl;
    }
    return 0;
}
