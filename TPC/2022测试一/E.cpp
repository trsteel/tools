#include <iostream>
#include <vector>
using namespace std;

const long maxn = 1e5 + 1;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long t, n, k, m;
  cin>>t;
  while(t--) {
    cin>>n>>k;
    vector<vector<int> > vec(k);
    for(int i=0;i<k;i++) {
      cin>>m;
      vec[i] = vector<int>(k);
      for(int j=0;j<m;j++) {
        cin>>vec[i][j];
      }
    }
    vector<int> top(n+1, -1);
    vector<int> idx(k, 0);
    int cnt = 0;
    bool chg = true;
    while(chg) {
      chg = false;
      for (int i = 0; i < k; i++) {
        if (idx[i] >= int(vec[i].size())) {
          continue;
        }
        int x = vec[i][idx[i]];
        if(x==0) continue;
        if (top[x] != -1 && top[x] != i) {
          cnt++;
          idx[i]++;
          idx[top[x]]++;
          top[x] = -1;
          chg = true;

        } else if (top[x] == -1) {
          top[x] = i;
          chg = true;
        }
      }
    }
    cout<<((cnt%2==0) ? "Nacho" : "Kelly") << endl;
  }
  return 0;
}