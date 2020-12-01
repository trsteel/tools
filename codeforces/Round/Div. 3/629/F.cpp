#include <iostream>
#include <algorithm>
using namespace std;
long long N,K,i,a,b,c,A[1<<19];
int main(){
	cin >> N >> K;
	for (i = 0; i < N; i++) cin >> A[i];
	sort(A,A+N);
	N--, K--;
	for (i = 0; i <= N-K; i++) {
		if (A[i] == A[i+K]) { cout << 0; return 0; }
	}
	for (i = 0; i <= K; i++) {
		a += A[K] - A[i];
		b += A[N-i] - A[N-K];
		c += abs(A[N/2] - A[i]);
	}
	for (; i <= N; i++) {
		a -= A[i] == A[K];
		b -= A[N-i] == A[N-K];
		c += abs(A[N/2]+1 - A[i]);
	}
 
	cout << min(a, min(b, c));
}