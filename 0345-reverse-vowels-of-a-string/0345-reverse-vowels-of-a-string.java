class Solution {
boolean isVowel(Character c) {
		return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
				|| c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
	public String reverseVowels(String s) {
		StringBuilder sb = new StringBuilder(s);
		int left = 0, right = sb.length()-1;
		while(left < right) {
			Character lc = sb.charAt(left);
			Character rc = sb.charAt(right);
			if (isVowel(lc) && isVowel(rc)) {
				// swap
				sb.setCharAt(left, rc);
				sb.setCharAt(right, lc);
				right--;
				left++;
			} else if (isVowel(lc)) {
				right--;
			} else if (isVowel(rc)) {
				left++;
			} else {
				right--; // or left++;
			}
		}
		return sb.toString();
	}
}