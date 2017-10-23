
class AllOne {
	unordered_map<string, pair<string, int> *> m;
	vector<pair<string, int> *> v;
public:
	/** Initialize your data structure here. */
	AllOne() {

	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		auto itr = m.find(key);
		if (itr != m.end()) {
			itr->second->second++;
		} else {
			auto p = new pair<string, int>(key, 1);
			v.push_back(p);
			m[key] = p;
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		auto itr = m.find(key);
		if (itr != m.end()) {
			if (itr->second->second == 1) {
				auto p = itr->second;
				auto ir = find(v.begin(), v.end(), p);
				if (ir != v.end())
					v.erase(ir);
				m.erase(itr);
				delete p;
			} else {
				itr->second->second--;
			}
		}
	}

	static bool cmp(pair<string, int> *a, pair<string, int> * b) {
		return a->second < b->second;
	}
	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (v.size() == 0) return "";
		sort(v.begin(), v.end(), cmp);
		return v.back()->first;
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (v.size() == 0) return "";
		sort(v.begin(), v.end(), cmp);
		return v.front()->first;
	}
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
