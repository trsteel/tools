class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = (unsigned long long)stoll(n);
        int max_pow = 1;
        unsigned long long  num1 = num;
        while(num1>0) max_pow++,num1>>=1;
        unsigned long long x = 1;
        for(int i=max_pow;i>1;i--) {
        	if((x<<i) < num) {
        		unsigned long long cur = search(num, i);
        		if(cur != 0) return to_string(cur);
        	}
        }
        return to_string(num-1);
    }

    unsigned long long search(unsigned long long n, int d) {
    	unsigned long long k = (unsigned long long)pow(n, 1.0/d);
    	unsigned long long s = 1;
    	while(s<=k) {
    		unsigned long long m = s+ ((k-s)>>1);
    		unsigned long long sum =1, cur = 1;
    		for(int i=1;i<=d;i++) cur*= m, sum+=cur;
    		if(sum == n) return m;
    		if(sum > n) k = m - 1;
    		else s = m + 1;
    	}
    	return 0;
    }
};