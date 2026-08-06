class LFUCache{
private:
    struct Node{
        int key;
        int value;
        int freq;
        Node(int k, int v, int f): key(k), value(v), freq(f){}
// this is alternative to this->key=k, this->value= v, this->freq=f
    };
    int capacity;
    int minFreq;

//key ->iterator pointing to the Node in freqTable. this is similar to the map used in LRU cache. 
    unordered_map<int, list<Node>::iterator> keyTable;

//Maps a freq count to a link list containing all keys with that frequency. Within each list, nodes are ordered by recency (just like in LRU cache)

//jaise 2-D array mai arr[i] points to ith 1-D array
    unordered_map<int, list<Node>> freqTable;

    void touch(Node& node){  //This helper runs whenever an item's frequency increases (on get or on updating an existing key via put)
        int oldFreq= node.freq;
        auto& oldList= freqTable[oldFreq];     //Fetches a reference to linked list for old freq
        auto it= keyTable[node.key];       //retrieves list iterator for this node
        Node node2= *it; //copy before erasing it
        
        oldList.erase(it);  //since its freq is gonna increase, remove from list of current freq

//If the old freq list is empty remove it, and if it was the minimum frequency, increment minFreq
        if (oldList.empty()) {
            freqTable.erase(oldFreq);
            if(minFreq== oldFreq) {
                minFreq++;
            }
        }

//Increment freq and add to front of new frequency list
        node2.freq++;
        freqTable[node2.freq].push_front(node2);

//Update keyTable reference 
        keyTable[node2.key] = freqTable[node2.freq].begin();
    }

public:
    LFUCache(int cap): capacity(cap), minFreq(0) {}

    int get(int key){
        if (keyTable.find(key) == keyTable.end()) {
            return -1;
        }
        auto it= keyTable[key];  //it has the address of the node

//Access the node by dereferencing the iterator, update its frequency, and return value
        Node& node = *it;
        int val = node.value;
        touch(node);  //updation work done here
        return val;
    }

    void put(int key, int val){
        if(capacity<=0){
            return;
        }

//If the key already exists, update value, and touch the node
        if(keyTable.find(key)!= keyTable.end()){
            auto it= keyTable[key];
            Node& node= *it;
            node.value= val;
            touch(node);
            return;
        }

//Evict LFU item if capacity is reached
        if (keyTable.size() >= capacity) {
            auto& minList = freqTable[minFreq];
            int evictKey = minList.back().key; // LRU item in lowest frequency bucket
// minList.back() gives us the node with lowest freq
        
            minList.pop_back();  //remove the node
            if (minList.empty()) {
                freqTable.erase(minFreq);
            }
            keyTable.erase(evictKey);
        }

//If the old key wasn't already existing, weiInsert it with its freq =1
        minFreq = 1;
        freqTable[1].push_front(Node(key, val, 1));
        keyTable[key] = freqTable[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */