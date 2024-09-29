class AllOne {
    unordered_map<string,int>mp;
    map<int,set<string>>freq;
public:
    AllOne() {

    }
    
    void inc(string key) {
        int cnt = mp[key];
        mp[key]++;
        if(cnt>0)freq[cnt].erase(key);
        freq[cnt+1].insert(key);
        if(freq[cnt].empty())freq.erase(cnt);
    }
    
    void dec(string key) {
        int cnt = mp[key];
        mp[key]--;
        freq[cnt].erase(key);
        if(cnt==1)mp.erase(key);
        else freq[cnt-1].insert(key);
        if(freq[cnt].empty())freq.erase(cnt);

    }
    
    string getMaxKey() {
        return freq.empty()?"":*(freq.rbegin()->second.begin());
    }
    
    string getMinKey() {
        return freq.empty()?"":*(freq.begin()->second.begin());

    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */