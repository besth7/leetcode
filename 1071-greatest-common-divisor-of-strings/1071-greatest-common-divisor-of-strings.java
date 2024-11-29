class Solution {
    static int calcGcd(int a, int b) {
		return b == 0 ? a : calcGcd(b, a % b);
	}
    public static String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) return "";
        
        int gcd = calcGcd(str1.length(), str2.length());
        return str2.substring(0, gcd);
    }
}