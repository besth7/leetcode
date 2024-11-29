class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ans = new int[nums.length];
        int zeroCount = 0;
        int multiple = 1;
        for (int i : nums) {
        	if (i == 0) {
                zeroCount++;
                if (zeroCount >= 2) return ans;
            }
        	else multiple *= i;
        }

        if (zeroCount == 0) {
        	for (int i=0; i<nums.length; i++) {
        		ans[i] = multiple / nums[i];
        	}
        } else {
        	for (int i=0; i<nums.length; i++) {
        		if (nums[i] == 0) ans[i] = multiple;
        	}
        }
        return ans;
    }
}