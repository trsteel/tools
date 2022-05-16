#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long maxn = 1e5 + 1;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long n, q, x, a;
  cin>>n;
  vector<long> vec;
  for(int i=0;i<n;i++) {
    cin>>a; vec.push_back(a);
  }
  sort(vec.begin(), vec.end(), less<int>());
  cin>>q;
  while(q--) {
    cin>>x;
    int p = upper_bound(vec.begin(), vec.end(), x) - vec.begin();
    cout<<p<<endl;
  }
  return 0;
}