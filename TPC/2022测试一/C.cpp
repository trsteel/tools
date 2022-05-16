#include <iostream>
using namespace std;

const long maxn = 1e3 + 1;
const long maxm = 1e4 + 1;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long n, m, a[maxn], b[maxn], c[maxm];
  cin>>n>>m;
  for(int i=0;i<n;i++) {
    cin>>a[i]>>b[i];
  }
  for(int i=0;i<=m;i++) c[i] = 0;
  long maxv = 0;
  for(int i=0;i<n;i++) {
    for(int j=m-a[i];j>=0;j--) {
      c[j+a[i]] = max(c[j+a[i]], c[j]+b[i]);
      maxv = max(maxv, c[j+a[i]]);
    }
  }
  cout<<maxv<<endl;
  return 0;
}