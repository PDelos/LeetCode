class RandomizedSet {
    unordered_set<int> us;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        auto it = us.find(val);
        if(it != us.end()) return false;
        us.insert(val);
        return true;
    }
    
    bool remove(int val) {
        size_t removed = us.erase(val);
        if (removed > 0) return true;
        return false;
    }
    
    int getRandom() {
        int pos = rand() % us.size();
        auto it = us.begin();
        advance(it, pos);
        return *it;
    }
};
