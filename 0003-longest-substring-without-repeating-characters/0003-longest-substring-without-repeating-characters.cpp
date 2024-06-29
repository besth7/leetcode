class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pivot = 0, result = 0;
        unordered_set<char> charSet;
        for (int i = 0; i<s.size(); i++) {
            while(charSet.find(s[i]) != charSet.end()) { // if find value
                charSet.erase(s[pivot]); // erase same char
                pivot++;
            }
            charSet.insert(s[i]);
            result = max(result, i - pivot + 1);
        }
        return result;
    }

};