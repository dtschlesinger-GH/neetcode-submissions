class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        internalMap[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto itr = internalMap[key].upper_bound(timestamp);
        return itr == internalMap[key].begin() ? "" : prev(itr)->second;
    }

    unordered_map<string, map<int, string>> internalMap;
};
