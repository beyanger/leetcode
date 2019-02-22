/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
    if (s[0] != '[') return NestedInteger(stoi(s));
        NestedInteger res;
        if (s.size() == 2) return res;
        int i, j, end = s.size()-1;
        for (i = j = 1; i < end; i++) {
            char c = s[i];
            if (c == ',') {
                res.add(deserialize(s.substr(j, i-j)));
                j = i+1;
            } else if (c == '[') {
                i++;
                for (int r = 1, l = 0; i < end; i++) {
                    if (s[i] == '[') r++;
                    else if (s[i] == ']') l++;
                    if (r == l) break;
                }
           }
        } 
        res.add(deserialize(s.substr(j, i-j)));
        return res;
    }
};
