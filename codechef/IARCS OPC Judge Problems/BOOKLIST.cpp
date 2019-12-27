#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	// your code goes here
	int m; cin>>m;
	vector<int> books(m);
	for(int i=0;i<m;i++) cin>>books[i];
	set<int> st;
	int n, i; cin>>n;
	while(n--) {
	    cin>>i;
	    i--;
	    for(int j: st) {
	        if(i<j) break;
	        i++;
	    }
	    cout<<books[i]<<endl;
	    st.insert(i);
	}
	return 0;
}
