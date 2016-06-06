class LRUCache{
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (map_.count(key)) {
            int value = (*map_[key]).second;
            list_.erase(map_[key]);
            list_.push_front({key, value});
            map_[key] = list_.begin();
            return value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if (map_.count(key)) {
            list_.erase(map_[key]);
            list_.push_front({key, value});
            map_[key] = list_.begin();
            return;
        }
        
        if (list_.size() < capacity_) {
            list_.push_front({key, value});
            map_[key] = list_.begin();
            return;
        }
        
        map_.erase(list_.back().first);
        list_.pop_back();
        list_.push_front({key, value});
        map_[key] = list_.begin();
    }
private:
    unordered_map<int, std::list<pair<int, int>>::iterator> map_;
    list<pair<int, int>> list_;
    int capacity_;
};
