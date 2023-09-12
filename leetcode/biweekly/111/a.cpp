// 2824
// https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/description/
// brute force

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] < target) ans++;
            }
        }
        return ans;
    }
};
