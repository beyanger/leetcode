
class RangeModule {
	typedef pair<int, int> PAIR;
	vector<PAIR> v;
public:
	RangeModule() {

	}

	void update() {
		sort(v.begin(), v.end(), [](const PAIR& a,const PAIR& b) {
				if (a.first != b.first) return a.first < b.first;
				return a.second < b.second;
				});

		for (int i = 1; i < v.size();) {
			if (v[i].first <= v[i-1].second) {
				v[i-1].second = max(v[i].second, v[i-1].second);
				v.erase(v.begin()+i);
			} else {
				i++;
			}
		}
	}

	void addRange(int left, int right) {
		v.push_back(make_pair(left, right));
	}

	bool queryRange(int left, int right) {
		update();
		auto itr = find_if(v.begin(), v.end(), [left, right](PAIR& p) {
				return p.first <= left && right <= p.second;
				});
		return itr != v.end();
	}

	void removeRange(int left, int right) {
		update();
		for (int i = 0; i < v.size();) {
			PAIR& pr = v[i];
			if (right <= pr.first) return;
			else if (pr.second <= left) {
				i++;
			} else if (left <= pr.first) {
				if (right < pr.second) {
					pr.first = right;
					i++;
				} else {
					v.erase(v.begin()+i);
				}
			} else if (pr.first < left) {
				if (right < pr.second) {
					v.insert(v.begin()+i+1, make_pair(right, pr.second));
					v[i].second = left;
					i += 2;
				} else {
					pr.second = left;
					i++;
				}
			}
		}
	}
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */


