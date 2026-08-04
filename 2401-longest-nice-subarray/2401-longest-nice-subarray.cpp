class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int left = 0;
        int mask = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            while (mask & nums[right]) {
                mask ^= nums[left];
                left++;
            }

            mask |= nums[right];

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};