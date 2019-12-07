class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        index[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(index.find(key) == index.end()) {
        	return "";
        }
        for(auto& it: index[key]) {
        	if(timestamp<it.first) {
        		continue;
        	}
        	return it.second;
        }
        return "";
    }
private:
	map<string, map<int, string, greater<int>>> index;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */