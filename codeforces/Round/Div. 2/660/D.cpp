#include <iostream>
#include <vector>
using namespace std;
const long maxn = 200001;
long n, a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    return 0;
}