class LRUCache {
public:
    list<pair<int,int>> order;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    int capacity = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!m.contains(key)) return -1;
        cout << "get, key: " << key << ", value: " << m[key]->second << endl;
        order.splice(order.end(), order, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        cout << "put, key: " << key << ", value: " << value << endl;
        if (m.contains(key)) {
            cout << "erased, key: " << key << ", value: " << value << endl;
            order.erase(m[key]);
            m.erase(key);
        } else if (order.size() >= capacity) {
            cout << "full capacity" << endl;
            cout << "erased, key: " << order.front().first << ", value: " << order.front().second << endl;
            m.erase(order.front().first);
            order.pop_front();
        }
        order.push_back({key, value});
        m[key] = --order.end();
    }
};
