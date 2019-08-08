class LRUCache {
private:
    int cap;
    //double linked list: save {key, val}
    list<pair<int, int>> cache;
    //hash table: key 映射到 (key, val) 在 cache中的位置
    unordered_map<int, list<pair<int, int>>::iterator> map; //value is a iterator

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if(it==map.end()){ //cannot find in map
            return -1;
        }
        else{ //found in map
            cache.splice(cache.begin(), cache, it->second); //put to cache front
        }
        return map[key]->second; //return mapped val
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it==map.end()){ //if key not in map
            if(cache.size()==cap){ //if cache full
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                //delete from both map and cache
                map.erase(lastKey);
                cache.pop_back();
            }
            //insert into front
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
        else{ //if in map, move to cache front
            cache.erase(map[key]);
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
