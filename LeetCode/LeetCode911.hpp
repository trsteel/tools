class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        map<int, int> index;
        int max_count = 1, max_v = persons[0];
        for(int i=0;i<persons.size();i++) {
        	index[persons[i]]++;
        	if(index[persons[i]]>=max_count) {
        		max_count = index[persons[i]];
        		max_v = persons[i];
        	}
        	votes.push_back(max_v);
        }
        timelines = times;
    }
    
    int q(int t) {
        if(t>=timelines.back()) {
        	return votes.back();
        }
        return votes[search(t, 0, timelines.size()-1)];
    }

    int search(int t, int s, int e) {
    	int m = (s+e) >> 1;
    	if(t<timelines[m]) {
    		return search(t, s, m-1);
    	} else if (t<timelines[m+1]){
    		return m;
    	} else {
    		return search(t, m+1, e);
    	}
    }

private:
	vector<int> votes;
	vector<int> timelines;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */