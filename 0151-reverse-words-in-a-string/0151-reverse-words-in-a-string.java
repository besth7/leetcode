class Solution {
    public String reverseWords(String s) {
        List<String> result = new ArrayList<>();
        StringBuilder temp = new StringBuilder();
        for (Character c : s.toCharArray()) {
        	if (c == ' ') {
        		if (temp.length() > 0) {
        			result.add(temp.toString());
                    temp.setLength(0);
        		}
        		continue;
        	}
        	temp.append(c);
        }
        
        if (temp.length() > 0) result.add(temp.toString());
        temp.setLength(0);
        
        for (int i=result.size()-1; i>=0; i--) {
        	temp.append(result.get(i));
        	if (i != 0) temp.append(" ");
        }
		return temp.toString();
    }
}