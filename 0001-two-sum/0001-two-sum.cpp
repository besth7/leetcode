class Solution {
public:
    int sum, idx1, idx2;
    vector<int> result;
    vector<int> twoSum(vector<int>& nums, int target) {
        result.clear();
        for (int idx1 = 0; idx1 < nums.size(); idx1++) {
            for (int idx2 = 1; idx2 < nums.size(); idx2++) {
                if (idx1 == idx2) continue;
                sum = nums[idx1] + nums[idx2];
                if (sum == target) {
                    result.push_back(idx1);
                    result.push_back(idx2);
                    return result;
                }
            }
        }
        return result;
    }
};