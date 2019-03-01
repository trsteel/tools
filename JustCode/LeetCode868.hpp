class Solution {
public:
    int binaryGap(int N) {
        int last = -1, cur = 0, dist = 0;
        while(N>0) {
        	cur++;
        	if(N%2) {
        		if (last!=-1) {
        			dist = dist==0?(cur-last):max(dist, cur-last);
        		}
        		last = cur;
        	}
        	N>>=1;
        }
        return dist;
    }
};