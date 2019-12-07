class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
    	if(hand.size()%W) return false;
        map<int, int> counts;
        for(int h: hand) {
        	counts[h]++;
        }
        while(counts.size()>0) {
        	for(auto& it:counts) {
        		int num = it.first;
        		for(int i=0;i<W;i++) {
        			if(counts.find(num+i)==counts.end()) return false;
        			if(--counts[num+i]==0) counts.erase(num+i);
        		}
        		break;
        	}
        }
        return true;

    }
};