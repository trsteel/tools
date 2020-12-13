#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    long long k, l, r, t, x, y;
    cin>>k>>l>>r>>t>>x>>y;
    unordered_set<long long> us;
    if (x>y) {
		if (y+k>r) k-=y;
		if ((k-l)/t>=x-y) cout<<"Yes";
		else cout<<"No";
	} else {
		if (x+y<=r-l) cout<<"Yes";
		else while (true) {
			long long d=(k-l)/x;
			t-=d,k-=d*x;
			if (us.count(k)||t<=0) {
				cout<<"Yes";
				return 0;
			}
			us.insert(k);
			if (k+y>r) {
				cout<<"No";
				return 0;
			}
			else k+=y;
		}
	}
    return 0;
}