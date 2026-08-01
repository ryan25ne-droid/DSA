// map-> {key, address}
//list-> {key, value}
class LRUCache {
private:
    int cap;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>> ::iterator> map;
public:
    LRUCache(int capacity){
        this->cap= capacity;        
    }
    
    int get(int key){
        if(map.find(key)==map.end()){
            return -1;
        }  
        auto it= map[key];
        int val= it->second;
        cache.erase(it);
        cache.push_front({key, val});
        map[key]= cache.begin();
        return val;      
    }
    
    void put(int key, int val){
        if(map.find(key)!= map.end()){
            cache.erase(map[key]);
        }       
        cache.push_front({key,val});
        map[key]= cache.begin();

        if(cache.size()>cap){
            auto last= cache.back();
            map.erase(last.first);
            cache.pop_back();
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */