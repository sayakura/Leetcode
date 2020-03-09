#include <iostream>

// dp not worth it, manacher's algorithm too complicated
class Solution {
public:
    string    longestPalindromeHelper(string s, int i, int j)  {
        while (i >= 0 && j < s.length()
              && s[i] == s[j])
        {
            i--;
            j++;
        }
        i
        return s.substr(i + 1, j - 1 - i); 
    }
    string  longestPalindrome(string s) {
        string ret;
        for (int i = 0; i < s.length(); i++)
        {
            string s1 = longestPalindromeHelper(s, i, i);
            string s2 = longestPalindromeHelper(s, i, i + 1);
            ret = ret.length() > s1.length() ? ret : s1;
            ret = ret.length() > s2.length() ? ret : s2;
        }
        return ret;
    }
};