class LRUCache {
    struct KV {
        int key, val;
        KV *prev, *next;
        KV(int k, int v) : key(k), val(v), prev(0), next(0) {}
    };

    KV head, tail;
    unordered_map<int, KV *> km;
    int cap;
    void update(KV *kv) {
        kv->next->prev = kv->prev;
        kv->prev->next = kv->next;
        kv->next = head.next;
        kv->prev = &head;
        head.next = kv;
        kv->next->prev = kv;
    }
public:
    LRUCache(int capacity) : head(0, 0), tail(0, 0) {
        head.next = &tail;
        tail.prev = &head;
        cap = capacity;
    }

    int get(int key) {
        auto p = km.find(key);
        if (p != km.end()) {
            update(p->second);
            return p->second->val;
        }
        return -1;
    }

    void put(int key, int value) {
        auto p = km.find(key);
        if (p != km.end()) {
            update(p->second);
            p->second->val = value;
        } else {
            if (km.size() >= cap) {
                KV *v = tail.prev;
                km.erase(v->key);
                v->val = value;
                v->key = key;
                update(v);
                km.insert(make_pair(key, v));
            } else {
                KV *v = new KV(key, value);
                v->next = head.next;
                v->next->prev = v;
                v->prev = &head;
                head.next = v;
                km.insert(make_pair(key, v));
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
