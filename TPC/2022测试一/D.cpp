#include <iostream>
#include <unordered_map>
using namespace std;

const long maxm = 1e7 + 1;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long t, n, m, x;
  cin>>t;
  while(t--) {
    cin>>n>>m;
    unordered_map<long, long> um[2];
    for(long i=0;i<n;i++) {
      cin>>x;
      long idx = i%2;
      long idx2 = (i+1)%2;
      um[idx2].clear();
      um[idx2][x%m] += 1;
      for(auto& it: um[idx]) {
        um[idx2][it.first] += it.second;
        um[idx2][(it.first+x)%m] += it.second;
      }
    }
    cout<<um[n%2][0]<<endl;
  }
  return 0;
}