class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, match = 0, left = 0, right = 0, mlen = numeric_limits<int>::max();
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        for (auto c: t) 
            needs[c]++;        
        while (right < s.length()) {
            char c1 = s[right++];
            window[c1]++;
            if (needs.count(c1) && needs[c1] == window[c1]) {
                match++;
            }
            while (match == needs.size()) {
                if (right - left < mlen) {
                    start = left;
                    mlen = right - left;
                }
                char c2 = s[left++];
                if (needs.count(c2)) {
                     if (--window[c2] < needs[c2])
                        match--;
                }
            }
        }
        return mlen == numeric_limits<int>::max() ? "" : s.substr(start, mlen);
    }
};