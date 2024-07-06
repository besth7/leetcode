class Solution {
public:
string expand_from_center(int left, int right, string s) {
    
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}
string longestPalindrome(string s) {
    if (s.length() < 2) return s;
    string result;
    for (int i=0; i<s.length() - 1; i++) {
        string odd = expand_from_center(i, i, s);
        string even = expand_from_center(i, i+1, s);
        if (odd.length() > result.length()) result = odd;
        if (even.length() > result.length()) result = even;
    }
    return result;

}
};