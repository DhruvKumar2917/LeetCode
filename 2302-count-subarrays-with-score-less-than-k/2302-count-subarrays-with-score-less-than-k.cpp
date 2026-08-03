class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int n = nums.size();

        int left = 0, right = 0;
        long long count = 0;
        long long sum = 0;
        long long multi = 1;

        while (right < n) {
            sum += nums[right];
            multi = (sum) * (right - left + 1);

            while (multi >= k && left <= right) {
                sum -= nums[left];
                left++;
                multi = (sum) * (right - left + 1);
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};