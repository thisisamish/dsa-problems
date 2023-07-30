// Approach 1 : Using hashmap
// TC is O(n), SC is O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            m[t[i]]--;
        }
        for (auto it: m) {
            if (it.second) return false;
        }
        return true;
    }
};

// Approach 2 : Sorting the strings
// TC is O(nlogn), SC is O(logn) or O(1) (depending on whether we consider space taken by sorting function or not) 

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) return true;
        return false;
    }
};