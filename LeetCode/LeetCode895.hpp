class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int x) {
    	// cout<<"push"<<x<<endl;
    	numbers.push_back(x);
    	removes.push_back(0);
    	delete_index(x);
        add_index(x);
    }
    
    int pop() {
    	int ans = 0;
        for(auto& idx: index) {
        	ans = (idx.first == 1) ? pop_tail() : pop_tail(idx.second);
        	break;
        }
        // cout<<"pop"<<ans<<endl;
        return ans;
    }

    int pop_tail() {
    	for(int i=numbers.size()-1;i>=0;i--) {
    		if(removes[i] == 0) {
    			removes[i] = 1;
    			delete_index(numbers[i]);
    			sub_index(numbers[i]);
    			return numbers[i];
    		}
        }
        return 0;
    }

    int pop_tail(map<int, bool>& idx) {
    	for(int i=numbers.size()-1;i>=0;i--) {
    		if(removes[i] == 0 && idx.find(numbers[i]) != idx.end()) {
    			removes[i] = 1;
    			delete_index(numbers[i]);
    			sub_index(numbers[i]);
    			return numbers[i];
    		}
        }
        return 0;
    }

    void delete_index(int x) {
    	if(index.find(counts[x]) == index.end()) {
    		return;
    	}
    	index[counts[x]].erase(x);
    	if(index[counts[x]].size()==0) {
    		index.erase(counts[x]);
    	}
    }

    void add_index(int x) {
    	counts[x]++;
    	index[counts[x]][x]=true;
    }

    void sub_index(int x) {
    	if(counts[x] < 2) {
    		counts.erase(x);
    		return;
    	}
    	counts[x]--;
    	index[counts[x]][x] = true;
    }

private:
	map<int, int> counts;
	map<int, map<int, bool>, greater<int>> index;
	vector<int> numbers;
	vector<int> removes;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */