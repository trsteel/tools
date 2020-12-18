#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long t, n, a[3001];
vector<long long> divs;

void findDiv(long long x) {
    divs.clear();
    for(long long i=1; i*i <= x;i++) if(x%i==0) {
        divs.push_back(i);
        if(i!=x/i) divs.push_back(x/i);
    }
    sort(divs.begin(), divs.end());
}


bool find(long long x) {
    long long ans = 0;
    for(long i=0;i<n;i++) {
        ans += a[i];
        if(ans == x) ans = 0;
        else if(ans > x) return false;
    }
    return ans == 0;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        long long sum = 0;
        for(int i=0;i<n;i++) {
            cin>>a[i]; sum += a[i];
        }
        // 求sum的约数
        findDiv(sum);
        long long res = n-1;
        for(long long i: divs) if(find(i)) {
            res = n-sum/i; break;
        }
        cout<<res<<endl;
    }
    return 0;
}